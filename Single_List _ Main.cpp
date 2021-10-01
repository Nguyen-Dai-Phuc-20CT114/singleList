/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream.h>
#include "single_list.h"
#include "string.h"
#include "Windows.h"

using namespace std;

class sinhVien_t
{
	private:
		static unsigned index;
	public:
		int stt;
		int diem;
		
		sinhVien_t()
		{
			++index;
			stt = diem = index;
		}
};
unsigned sinhVien_t::index = 0;

template<class data_t>
void inDSSV(std::string s, singleList_t<data_t> *head)
{
	std::cout << "\n\n\n After " << s << " 2 students: ";

	int i = 0;
	singleList_t<sinhVien_t> *sv_curr = head;
	while(sv_curr != nullptr)
	{
		std::cout << sv_curr->data.stt;
		if(sv_curr->get_next() != nullptr){
			std::cout << " -> ";
		}
		sv_curr = sv_curr->get_next();
		++i;

		if(i > 21){break;}
	}

	std::cout << "\n";
}


void printSinhVien(sinhVien_t sinhVien)
{
	std::cout << "stt: " << sinhVien.stt << " : " << "diem: " << sinhVien.diem << "\n";
}



int main()
{
	
	// singleList_t<sinhVien_t> *lopA_head = nullptr;
	// singleList_t<sinhVien_t> *lopA_tail = create_List(lopA_head, 2);

	// inDSSV("A create", lopA_head);
	

	// add_Head(lopA_head, 2, STACK);
	// inDSSV("A add first (stack mode)", lopA_head);

	
	// add_Head(lopA_head, 2, QUEUE);
	// inDSSV("A add first (queue mode)", lopA_head);


	// add_Tail(lopA_tail, 2);
	// inDSSV("A add last", lopA_head);



	// singleList_t<sinhVien_t> *lopB_head = nullptr;
	// singleList_t<sinhVien_t> *lopB_tail = nullptr;


	// add_Head(lopB_head, 2, QUEUE);
	// inDSSV("B add head	(queue mode)", lopB_head);


	// add_Head(lopB_head, 2, STACK);
	// inDSSV("B add head (stack mode)", lopB_head);


	// lopB_tail = get_Tail(lopB_head);


	// add_Tail(lopB_tail, 2);
	// inDSSV("B add tail", lopB_head);


	// std::cout << add_Before(lopB_head, 2, 0, QUEUE);
	// inDSSV("B add before 0 (queue)", lopB_head);

	// add_Before(lopB_head, 2, 0, STACK);
	// inDSSV("B add before 0 (stack)", lopB_head);

	// add_Before(lopB_head, 2, 2, QUEUE);
	// inDSSV("B add before 2 (stack)", lopB_head);

	// add_Before(lopB_head, 2, 2, STACK);
	// inDSSV("B add before 2 (stack)", lopB_head);
	


	singleList_t<sinhVien_t> *lopC_head = nullptr;
	singleList_t<sinhVien_t> *lopC_tail = nullptr;

	// add_Head(lopC_head, 2);
	// inDSSV("C add head (null)", lopC_head);

	// add_Tail(lopC_tail, 2);
	// inDSSV("C add tail (null)", lopC_tail);

	// add_Before(lopC_head, 2, 0, QUEUE);
	// inDSSV("C add before 0 (null) (queue)", lopC_head);

	// add_Before(lopC_head, 2, 0, STACK);
	// inDSSV("C add before 0 (null) (stack)", lopC_head);

	// add_After(lopC_head, lopC_tail, 2, 0);
	// inDSSV("C add after 0 (null)", lopC_head);



	lopC_tail = create_List(lopC_head, 2);
	inDSSV("C create", lopC_head);



	add_Head(lopC_head, 2);
	inDSSV("C add head", lopC_head);

	add_Tail(lopC_tail, 2);
	inDSSV("C add tail", lopC_head);

	add_Before(lopC_head, 2, 0, QUEUE);
	inDSSV("C add before 0 (queue)", lopC_head);

	add_Before(lopC_head, 2, 0, STACK);
	inDSSV("C add before 0 (stack)", lopC_head);

	add_After(lopC_head, lopC_tail, 2, 0);
	inDSSV("C add after 0", lopC_head);



	/*** add_Before() ***/



	// add_Before(lopC_head, 2, -1, QUEUE);
	// inDSSV("C add before -1 (queue)", lopC_head);

	// add_Before(lopC_head, 2, -1, STACK);
	// inDSSV("C add before -1 (stack)", lopC_head);

	// add_Before(lopC_head, 2, 40, QUEUE);
	// inDSSV("C add before 40 (queue)", lopC_head);

	// add_Before(lopC_head, 2, 40, STACK);
	// inDSSV("C add before 40 (stack)", lopC_head);

	// add_Before(lopC_head, 2, 11, QUEUE);
	// inDSSV("C add before 11 (queue)", lopC_head);

	// add_Before(lopC_head, 2, 13, STACK);
	// inDSSV("C add before 13 (stack)", lopC_head);

	// add_Before(lopC_head, 2, 2, QUEUE);
	// inDSSV("C add before 2 (queue)", lopC_head);

	// add_Before(lopC_head, 2, 2, STACK);
	// inDSSV("C add before 2 (stack)", lopC_head);



	/*** add_After ***/



	// add_After(lopC_head, lopC_tail, 2, -1);
	// inDSSV("C add after -1", lopC_head);

	// add_After(lopC_head, lopC_tail, 2, -1);
	// inDSSV("C add after -1", lopC_head);

	add_After(lopC_head, lopC_tail, 2, 40);
	inDSSV("C add after 40", lopC_head);

	add_After(lopC_head, lopC_tail, 2, 40);
	inDSSV("C add after 40", lopC_head);

	add_After(lopC_head, lopC_tail, 2, 11);
	inDSSV("C add after 11", lopC_head);

	add_After(lopC_head, lopC_tail, 2, 12);
	inDSSV("C add after 12", lopC_head);

	delete_Head(lopC_head, lopC_tail, 2);
	inDSSV("c delete head", lopC_head);

	delete_Tail(lopC_head, lopC_tail, 14);
	inDSSV("c delete tail", lopC_head);

	std::cout << "\n";
	
    return 0;
}

