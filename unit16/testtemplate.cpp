template <typename T> class Blob {
	friend class BlobPtr;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	//���캯��
	Blob();

	Blob(std::initializer_list<T> il);
	//Blob�е�Ԫ����Ŀ
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//��Ӻ�ɾ��Ԫ��
	void push_back(const T &t) { data->push_back(t); }
	//�ƶ��汾
	void push_back(const T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	//Ԫ�ط���
	T& back();
	T &operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	//��data[i]��Ч�����׳�msg
	void check(size_type i, const std::string &msg) const;
};
//2016��7��1��20:35:55
//ʵ����

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data.size())
		throw std::out_of_rang(msg);
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	//���i̫��check���׳��쳣����ֹ����һ�������ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
	data(std::make_shared<std::vector<T>>(il)) {}

template <typename T> class BlobPtr {
public:
	BlobPtr():curr(0) {}
	BlobPtr(Blob<T> &a,size_t sz = 0):
		wptr(a.data),curr(sz) {}
	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];	//(*p)Ϊ������ָ���vector
	}
	//�����͵ݼ�
	BlobPtr& operator++();	//ǰ�������
	BlobPtr& operator--();
private:
	//�����ɹ���check����һ������vector��shared_ptr
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&) const;
	//����һ��weak_ptr,��ʾ�ײ�vector���ܱ�����
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;			//�����е�ǰλ��
};

template <typename T>
BlobPtr<T> BlobPtr::operator++(int)
{
	//�˴������飻����ǰ�õ���ʱ����м��
	BlobPtr ret = *this;	//���浱ǰֵ
	++*this;				//�ƽ�һ��Ԫ��;ǰ��++�������Ƿ�Ϸ�
	return ret;				//���ر���״̬.
}

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);