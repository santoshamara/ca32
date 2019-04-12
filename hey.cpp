#include<iostream>
using namespace std;
int absolute(int a,int b)
    {int c;
     c=a-b;
     if(c<0)
            return -c;
     else
         return c;
         }

int main()
{
    int m,n,x,start,i,j,pos,a[15],count;
     count=0;
     cout<<"\nEnter the number of cylinders :";
     cin>>m;
     cout<<"\nEnter the number of requests :";
     cin>>n;
     cout<<"\nEnter current position :";
     cin>>start;
     cout<<"\nEnter the request queue :";
     for(i=0;i<n;i++)
                     {
                         cin>>a[i];
                      if(a[i]>=m)
                       {  cout<<"\ninvalid input\n";
                                  cin>>a[i];
                        }
                     }
    cout<<"Scheduling Services the request in the order that follows:\n"<<start<<"\t";
                              count=0;
                              pos=0;
                              //for sorting the  request queue
                              for(i=0;i<n;i++)
                               {
                                   for(j=0;j<n-i-1;j++)
                                    {
                                       if(a[j]>a[j+1])
                                      {
                                          x=a[j];
                                          a[j]=a[j+1];
                                          a[j+1]=x;
                                       }

                                  }

                               }

                             for(i=0;i<n;i++)
                                             if(a[i]<start)
                                                           pos++;
                             x=start;
                             for(i=pos;i<n;i++)
                                               {count+=absolute(x,a[i]);
                                                x=a[i];
                                                cout<<"\t"<<x;
                                                }
                             for(i=0;i<pos;i++)
                                                {count+=absolute(x,a[i]);
                                                 x=a[i];
                                                 cout<<"\t"<<x;
                                                 }
                             for(i=0;i<n;i++)
                                             cout<<"\t"<<a[i];
                             cout<<"\nTotal Head movement:"<<count<< "Cylinders";


}
