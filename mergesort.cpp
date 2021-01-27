# include<iostream>
using namespace std;
class merge
{
	public:
		int arr[10];
		int n;
		public:
		void input();
		void display();
		void merge_sort(int arr[10],int beg,int e);
        void merge_(int arr[10],int big,int mid,int e);
};
void merge::input()
{
	cout<<"Enter the size of the array:";
	cin>>n;
	cout<<"Enter the element of the array:";
	for(int i=0;i<n;i++)


{
		cin>>arr[i];
	}
merge_sort(arr,0,n-1);
}

void merge::display()
{
	cout<<"The element of the array is:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";

	}
}
void merge::merge_sort(int arr[10],int beg,int e)
{int mid;
    if(beg<e)
    {
        mid = (beg+e)/2;
          cout<<"mid is"<<mid;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,e);
        merge_(arr,beg,mid,e);

    }
}
  void merge ::merge_(int arr[10],int lb,int mid,int ub)
  {    int b[10];
      int i = lb;
      int l;
      int j = mid+1;
      int k = lb;
      while(i<= mid&& j<=ub)
      {
          if(arr[i]<=arr[j])
          {
              b[k] = arr[i];
              i++;
          }
          else
          {
              b[k] = arr[j];
              j++;

          }
          k++;
      }
      if(i>mid)
      {
          while(j<=ub)
          {

            b[k] = arr[j];
          j++;
          k++;
          }}
          else
            {while(i<=mid)
          {
              b[k] = arr[i];
              i++;
              k++;

          }}
          l = lb;
          while(l<k)
   {

         arr[l] = b[l];
         l++;
  }

      }


int main()
{
	merge ob1;
	ob1.input();
	ob1.display();
	return 0;
}
