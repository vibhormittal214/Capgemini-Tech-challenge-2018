#include<iostream>
#include<bits/stdc++.h>
#include <string>
#include<algorithm>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int ar1[],int exi[],int exj[],int low, int high)
{
    int temp[1][2];
    int pivot = ar1[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (ar1[j] <= pivot)
        {
            i++;
            swap(&ar1[i], &ar1[j]);
            swap(&exi[i], &exi[j]);swap(&exj[i], &exj[j]);
        }
    }
    swap(&ar1[i + 1], &ar1[high]);
    swap(&exi[i+1], &exi[high]);swap(&exj[i+1], &exj[high]);
    return (i + 1);
}
void quickSort(int ar1[],int exi[],int exj[],int low, int high)
{
    if (low < high)
    {
        int pi = partition(ar1,exi,exj,low, high);
        quickSort(ar1,exi,exj,low, pi - 1);
        quickSort(ar1,exi,exj,pi + 1, high);
    }
}
int main(){
   string str1;
   cin>>str1;
   int *ar1,*exi,*exj;
   ar1=new int[8];
   exi=new int[8];
   exj=new int[8];
   size_t row=std::count(str1.begin(),str1.end(),'#');
   int t=str1.find('#');
   std::string str2 = str1.substr (0,t);
   size_t col=std::count(str2.begin(),str2.end(),'@');
   col=col+1;row=row+1;
   //cout<<row<<'\n'<<col;
   int mat[row][col];
    int myint1,addx=0;
   int present[row*col][2];
   int i=0,stlen=0;char st;int j=0;
   string m1="";
   while(stlen<str1.length()){
    st=str1[stlen];
    if(st=='@'||st=='#'){

    }
    else{
    m1=m1+st;}
    if(st=='@'||st=='#'||stlen==str1.length()-1){
        //cout<<m1<<" ";
        stringstream geek(m1);
            geek>>myint1;
            mat[i][j]=myint1;
            if(myint1==-1){
                present[addx][0]=i;
                present[addx][1]=j;
                addx++;
            }
        m1="";

    }
    if(st=='@')
    {

        j++;
    }
    else if(st=='#'){
               if(j==col-1)
               j=0;

        i++;
        }

    stlen++;
   }
   //comparison starts
   int n1,n2,n3,n4,n5,n6,n7,n8;
   int cost=0;
   for(int x=0;x<addx;x++){
        i=present[x][0];
        j=present[x][1];
        //cout<<i<<j<<"this";
        //cout<<"\n";
        //case 1
        if(row==1 && col==1)
        {
           // cout<<i<<j;
            if(row==i-1&&col==j-1)
              cout<<0;
            else
                cout<<mat[i][j];

        }//case 1 end
        //case 2
        else if(row==1){
            if(i==0&&j==0){
            ar1[0]=mat[i][j+1];
            if(ar1[0]!=-1){
                cost=cost+mat[i][j+1];
                mat[i][j+1]=-1;
                continue;}
            }
            else if(i==0&& j==col-1){
               ar1[0]=mat[i][j-1];
                if(ar1[0]!=-1){
                cost=cost+mat[i][j-1];
                mat[i][j-1]=-1;
                continue;}
            }
            else{
                ar1[0]=mat[i][j+1];
                ar1[1]=mat[i][j-1];
                exi[0]=i;exi[1]=i;
                exj[0]=j+1;exj[1]=j-1;
                quickSort(ar1,exi,exj,0,1);
//                cout<<[0];
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;

                }
            }
            }//case2 end
            //case 3
        else if(col==1){
            if(i==0&&j==0){
            ar1[0]=mat[i+1][j];
            if(ar1[0]!=-1){
                cost=cost+mat[i+1][j];
                mat[i+1][j]=-1;
                continue;}

            }
            else if(j==0&& i==row-1){
               ar1[0]=mat[i-1][j];
                if(ar1[0]!=-1){
                cost=cost+mat[i-1][j];
                mat[i-1][j]=-1;
                continue;}
            }
            else{
                ar1[0]=mat[i+1][j];
                ar1[1]=mat[i-1][j];
                exi[0]=i+1;exi[1]=i-1;
                exj[0]=j;exj[1]=j;
                quickSort(ar1,exi,exj,0,1);
//                cout<<[0];
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;

                }
            }
            }
        else
        {
            int i1,j1;
            //case 1
            if(i==0 && j==0){
         //           cout<<"haha";
                i1=i+1;j1=j+1;
                ar1[0]=mat[i][j1];
                ar1[1]=mat[i1][j];
                ar1[2]=mat[i1][j1];
                exi[0]=i;exi[1]=i1;exi[2]=i1;
                exj[0]=j1;exj[1]=j;exj[2]=j1;
                quickSort(ar1,exi,exj,0,2);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }
            else if(i==row-1 && j==col-1){
                i1=i-1;j1=j-1;
                ar1[0]=mat[i][j1];
                ar1[1]=mat[i1][j];
                ar1[2]=mat[i1][j1];
                exi[0]=i;exi[1]=i1;exi[2]=i1;
                exj[0]=j1;exj[1]=j;exj[2]=j1;
                quickSort(ar1,exi,exj,0,2);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }
            else if(i==row-1 && j==0){
                i1=i-1;j1=j+1;
                ar1[0]=mat[i][j1];
                ar1[1]=mat[i1][j];
                ar1[2]=mat[i1][j1];
                exi[0]=i;exi[1]=i1;exi[2]=i1;
                exj[0]=j1;exj[1]=j;exj[2]=j1;
                quickSort(ar1,exi,exj,0,2);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }
            else if(i==0 && j==col-1){
                i1=i+1;j1=j-1;
                ar1[0]=mat[i][j1];
                ar1[1]=mat[i1][j];
                ar1[2]=mat[i1][j1];
                exi[0]=i;exi[1]=i1;exi[2]=i1;
                exj[0]=j1;exj[1]=j;exj[2]=j1;
                quickSort(ar1,exi,exj,0,2);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }
            else if(j==0){
                ar1[0]=mat[i-1][j];
                ar1[1]=mat[i+1][j];
                ar1[2]=mat[i][j+1];
                ar1[3]=mat[i-1][j+1];
                ar1[4]=mat[i+1][j+1];
                exi[0]=i-1;exi[1]=i+1;exi[2]=i;exi[3]=i-1;exi[4]=i+1;
                exj[0]=j;exj[1]=j;exj[2]=j+1;exj[3]=j+1;exj[4]=j+1;
                quickSort(ar1,exi,exj,0,4);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
                continue;
            }
            else if(j==col-1){
                ar1[0]=mat[i][j-1];
                ar1[1]=mat[i+1][j];
                ar1[2]=mat[i-1][j];
                ar1[3]=mat[i-1][j-1];
                ar1[4]=mat[i+1][j-1];
                exi[0]=i;exi[1]=i+1;exi[2]=i-1;exi[3]=i-1;exi[4]=i+1;
                exj[0]=j-1;exj[1]=j;exj[2]=j;exj[3]=j-1;exj[4]=j-1;
                quickSort(ar1,exi,exj,0,4);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }

            else if(i==0){
                ar1[0]=mat[i][j-1];
                ar1[1]=mat[i][j+1];
                ar1[2]=mat[i+1][j];
                ar1[3]=mat[i+1][j-1];
                ar1[4]=mat[i+1][j+1];
                exi[0]=i;exi[1]=i;exi[2]=i+1;exi[3]=i+1;exi[4]=i+1;
                exj[0]=j-1;exj[1]=j+1;exj[2]=j;exj[3]=j-1;exj[4]=j+1;
                quickSort(ar1,exi,exj,0,4);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }

            else if(i==row-1){
                ar1[0]=mat[i][j-1];
                ar1[1]=mat[i][j+1];
                ar1[2]=mat[i-1][j];
                ar1[3]=mat[i-1][j-1];
                ar1[4]=mat[i-1][j+1];
                exi[0]=i;exi[1]=i;exi[2]=i-1;exi[3]=i-1;exi[4]=i-1;
                exj[0]=j-1;exj[1]=j+1;exj[2]=j;exj[3]=j-1;exj[4]=j+1;
                quickSort(ar1,exi,exj,0,4);
                if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                }
            }
            else{
                    ar1[0]=mat[i][j-1];
                    ar1[1]=mat[i][j+1];
                    ar1[2]=mat[i-1][j-1];
                    ar1[3]=mat[i-1][j];
                    ar1[4]=mat[i-1][j+1];
                    ar1[5]=mat[i+1][j-1];
                    ar1[6]=mat[i+1][j];
                    ar1[7]=mat[i+1][j+1];
                    exi[0]=i;exi[1]=i;exi[2]=i-1;exi[3]=i-1;exi[4]=i-1;exi[5]=i+1;exi[6]=i+1;exi[7]=i+1;
                    exj[0]=j-1;exj[1]=j+1;exj[2]=j-1;exj[3]=j;exj[4]=j+1;exj[5]=j-1;exj[6]=j;exj[7]=j+1;
                    quickSort(ar1,exi,exj,0,4);
                    if(ar1[0]!=-1){
                    cost=cost+ar1[0];
                    mat[exi[0]][exj[0]]=-1;
                    }
            }

        }

   }
   if(row==1){
    for(i=0;i<col;i++){
        if((mat[row][i]!=-1)&&(mat[row][i-1]==-1 &&mat[row][i+1]==-1)){
            cost=cost+mat[row][i];
            mat[row][i]=-1;
        }
    }
   }
   cout<<cost;
   for(i=0;i<row;i++){
    for(j=0;j<col;j++){
       cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
   }

   return 0;
}
