 
void insert_max_heap(HeapType* h, element item);              
element delete_max_heap(HeapType* h);                      
init(HeapType* h);                                            
void sort_clock();                                           

	int main()
	{

		int i; //반복을 돌리기위해 선언
		int a = 1;

		printf("데이터의 개수를 입력 하시오 : ");
		scanf("%d", &n);

		printf("-----------최선------------\n");
	for (i = 0; i < n; i++) { //최선 
		selection_Sort[i] = a; //선택
		insertion_Sort[i] = a; //삽입
		merge_Sort[i] = a; //합병
		heap_Sort[i] = a++; //히프
	}
	sort_clock();

	printf("-----------최악------------\n");
	for (i = 0; i < n; i++) { //최악 
		selection_Sort[i] = --a;
		insertion_Sort[i] = a;
		merge_Sort[i] = a;
		heap_Sort[i] = a;
	}
	sort_clock();

	system("PAUSE");
}



		//선택 정렬
void selection_sort(int list[], int n)
{
	
}
