#include <vector>
#include <iostream>
#include <algorithm>


class Object
{
	public:
		Object()
		{}
		~Object()
		{}
		if(std::find())
		void AddInt(int num)
		{
			m_VectorOfInts.push_back(num);
		}
		std::vector<int> GetCopyOfVector()
		{
			return m_VectorOfInts;
		}
		void DisplayVectorContents()
		{
			for( unsigned int i = 0; i < m_VectorOfInts.size(); i++ )
			{
				std::cout << "Element[" << i << "] = " << m_VectorOfInts[i] << std::endl;
			}
			std::cout << std::endl;
		}

	private:
		std::vector<int> m_VectorOfInts;
};

// if(std::find(v.begin(), v.end(), x) != v.end()) {
// 	/*v contains x*/
// }
// else {
// 	/* v is empty */
// }