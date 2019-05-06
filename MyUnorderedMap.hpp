
#include "MyUnorderedMap.h"

void get_identity(std::string & my_id)
{

  my_id = "jmr3by";

}



/// hash number to an index
// algoritum works but we need to test in class
template <typename K, typename V>
int MyUnorderedMap<K, V>::hash(const K & key)const
{

    // for strings only

    int i;
    int sum =0;
    for(int i =0;key[i] != '\0';i++)
    {

        sum += (int)key[i];

    }

    return sum % reserved_size; // some hash code


}
template <typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap()
{

    data_size = 0;
    reserved_size =0;
    m_data = nullptr;


}
template <typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap(const MyUnorderedMap<K, V> & source)
{
    std::string empty = "wehoufbweo";
    reserve(source.reserved_size);
    data_size = source.data_size;
    for(int i = 0; i< source.reserved_size;i++)
    {

        if(source.m_data[i].first != empty)
        {

           m_data[i] = MyPair<K,V>(source.m_data[i].first,source.m_data[i].second);

        }
    }

}
template <typename K, typename V>
MyUnorderedMap<K, V> & MyUnorderedMap<K,V>::operator=(const MyUnorderedMap<K, V> & source)
{
    clear();
    std::string empty = "wehoufbweo";
    reserve(source.reserved_size);
    data_size = source.data_size;
    for(int i = 0; i< source.reserved_size;i++)
    {

        if(source.m_data[i].first != empty)
        {

           m_data[i] = MyPair<K,V>(source.m_data[i].first,source.m_data[i].second);

        }

    }
    return *this;


}
template <typename K, typename V>
MyUnorderedMap<K, V>::~MyUnorderedMap()
{
    delete [] m_data;

}
template <typename K, typename V>
V & MyUnorderedMap<K, V>::at(const K &key)
{


  if(count(key) == 0)
  {

    throw std::out_of_range("Key is not in the hash table");

  }
  std::string epty ="wehoufbweo";
  int home = hash(key); /// index value in array
  int pos = home;
  for(int i = 1;m_data[pos].first != key && m_data[pos].first != epty;i++)
  {

      pos = (home + i)%reserved_size;

  }

  return m_data[pos].second;



}
template <typename K, typename V>
V & MyUnorderedMap<K,V>::operator[](const K & key)
{

    if(count(key)==0)
    {

        insert(MyPair<K,V>(key));


    }
    if(count(key) != 0)
    {
        std::string epty ="wehoufbweo";

        int home = hash(key); /// index value in array
        int pos = home;
        for(int i = 1;m_data[pos].first != key && m_data[pos].first != epty;i++)
        {

            pos = (home + i)%reserved_size;

        }



        return m_data[pos].second;


    }


}
template <typename K, typename V>
bool MyUnorderedMap<K,V>::empty() const
{

  return data_size==0;


}
template <typename K, typename V>
int MyUnorderedMap<K,V>::size() const
{

  return data_size;

}
template <typename K, typename V>
void MyUnorderedMap<K,V>::clear()
{

    data_size = 0;
    reserved_size =0;
    delete [] m_data;
    m_data = nullptr;


}
template <typename K, typename V>
void MyUnorderedMap<K,V>::insert(const MyPair<K, V> &init_pair)
{



    /// reserve function to be called

        if(data_size ==  reserved_size*(0.6))
        {

           reserve(2*reserved_size);


        }
        if(data_size == reserved_size*(0.1))
        {

            reserve(reserved_size*0.3);

        }
        if(data_size >= reserved_size)
        {

            reserve(reserved_size+20);

        }
        K key = init_pair.first;

        K empty = "wehoufbweo";
        int pos = hash(key);
        auto home_value = pos;
        for(int i =1;(empty != m_data[pos].first) && (key != m_data[pos].first);i++)
        {

              pos = (home_value + i)%reserved_size;


        }
        data_size++;
        //try this first
        m_data[pos] = init_pair;


}
template <typename K, typename V>
void MyUnorderedMap<K, V>::erase(const K &key)
{

    if(reserved_size > 0)
    {

        int home = hash(key);
        int pos = home;
        std::string elpty = "wehoufbweo";
        for(int i = 1; (m_data[pos].first != key) && (m_data[pos].first != elpty);i++)
        {

            pos = (home + i)%reserved_size;


        }
        m_data[pos] = elpty;


    }
    if(data_size == reserved_size*(0.1))
    {

        reserve(reserved_size*0.3);

    }


}
template <typename K, typename V>
MyPair<K, V> * MyUnorderedMap<K,V>::find(const K & key)const
{
    //assume works idealy
    /// return a nullptr
    // or
    // return a MyPair
    if(reserved_size>0)
    {
        int home; // homevalue
        int pos = hash(key);
        K epy = "wehoufbweo";
        home = pos;
        for(int i=1; (key != m_data[pos].first) && (epy != m_data[pos].first);i++)
        {
            // probe seqiucent is linear
            pos = (home + i)%reserved_size;

        }
        if(key == m_data[pos].first)
        {

            return &m_data[pos];

        }

        else
        {

           return nullptr;


        }

    }
    else
    {

        return nullptr;

    }

}
template <typename K, typename V>
void MyUnorderedMap<K,V>::print()const
{
    cout<<"(";
    std::string empty_string = "wehoufbweo";
    for(int i =0;i<reserved_size;i++)
    {

        if(m_data[i].first != empty_string)
        {

            cout<<"["<<m_data[i].first<<"]"<<"="<<m_data[i].second<<endl;

        }



    }



}
template <typename K, typename V>
int MyUnorderedMap<K, V>::count(const K &key)const
{
    /// test of find passed
    MyPair<K, V> * pointer = find(key);

    if(pointer == nullptr)
    {

      return 0;

    }
    else
    {

      return 1;

    }


}
template <typename K, typename V>
void MyUnorderedMap<K, V>::reserve(int new_cap)
{
    /// trust find works test find first before run
    // 1
    MyPair<K, V> * New_size = new MyPair<K, V>[new_cap];
    // old = 5
    int old_reserve_size = reserved_size;
    // == 10
    reserved_size = new_cap;


    K Empty = "wehoufbweo";
    for(int i =0;i<new_cap;i++)
    {

        New_size[i].first = Empty;


    }
    for(int i =0; i < old_reserve_size;i++)
    {


        // distrubut data to other array
        if((m_data[i].first != Empty))
        {
            // hash into
            int hash_value = hash(m_data[i].first); // compute new index
            int home = hash_value;
            int pos = home;
            // assume no dublicate keys
          //  New_size[hash_value] = find(m_data[i].first);

            for(int j = 1; (New_size[pos].first != m_data[i].first) && (New_size[pos].first != Empty);j++)
            {


                pos = (j + home)%reserved_size;



            }
            New_size[pos] = m_data[i];




        }


    }
    delete [] m_data;
    m_data = New_size;


}

void get_virus_frequency(MyUnorderedMap<std::string, int> &in_tree)
{


  




}
