#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string.h>
#include<stdio.h>                   //Declaring all the necessary required header files
using namespace std;

//A function to compare two strings passed in  it*************************************************************************************
long int compare(string a,string b)
{
    long int n=a.length(),c=0,d=0,k;

    for(long int i=0;i<n;i++)
    {
        if(a[i]!=b[i])            //Checking 2 strings element by element
        {
            c++;
            k=i;
        }
        else if(a[i]==b[i])
            d++;
    }
    if(c==1) return k;
    else if(d==n) return -2;     //returning the required value
    else return -1;
}


// A function to covert to binary values*****************************************************************************************
string convert_zero_one(long int n,long int m)
{
    string a;
    for(long int i=0;i<m;i++)
    {
        if(n%2==0)
            a.push_back('0');
        else                          //Adding the values 0 and 1 to the vextor for binary representation
            a.push_back('1');
        n=n/2;
    }
    reverse(a.begin(),a.end());       //reversing the string
    return a;
}
// A function to add '_' to the string*********************************************************************************************
string change(string a,long int l)
{
    a[l]='_';               //adding the character '_' to the l-1th element of string
    return a;
}
//A function to get the required function********************************************************************************************
void investigatefunction(string a,vector<string>&b)
{
    long int flag=0,n=b.size();
    for(long int i=0;i<n;i++)
    {
        if(compare(a,b[i])==-2)     //terminate the function here
        {return;}
        else
        {flag++;}
    }
    if(flag==n)
        b.push_back(a);
    return;
}
// Declaration of main for the next processes***************************************************************************************
 int main()
{
    long int in,jn,kn;
    vector<vector<string> >fn; //Declaring a vector containing functions
    long int fun_num,no;
    cout<<"*****Please sir, enter the number of functions(followed by enter)*******";
    cin>>fun_num;        //taking number of functions*****************************************************************************
    cout<<"******Please sir how many variables are there(followed by enter)**********";
    cin>>no;             //Taking number of variables******************************************************************************
    vector<vector<long int> >mn;
    vector <long int> mnterm;
    for(in=0;in<fun_num;in++)
    {
        vector<long int >waste;
        long int m1;

        cout<<"How many min terms do function"<<in+1<<"has? "; //Take the min terms of the functions
        cin>>m1;
        mnterm.push_back(m1);
        cout<<"Tell their values(decimal representation) --->";  //Take the decimal values of the min terms
        for(jn=0;jn<m1;jn++)
        {
            long int a;
            cin>>a;                //Adding the min terms to vector waste(pushing)******************************************************
            waste.push_back(a);
        }

        mn.push_back(waste);
    }
    for(in=0;in<fun_num;in++)
    {
        long int c=0;
        vector<long int >waste1;
        for(jn=0;jn<pow(2,no);jn++)
        {
            if(mn[in][c]!=jn)
                waste1.push_back(jn);
            else
                c++;
        }
        mn.push_back(waste1);
    }
    //Doing the tabulation to find the minimized form************************************************************************************
    for(long int i1=0;i1<(2*fun_num);i1++)
    {

           long int i,j,k,n,m,l,major,minor,count;
    n=mn[i1].size();
    vector<string>vecnew,terms,vect,prime,temp1,ep;
  vector<long int>newvect2;vector<pair<long int,long int> >wicd3;
     long int a[n];

for(long int r1=0;r1<n;r1++)
{      a[r1]=mn[i1][r1];}
  for(long int i=0;i<n;i++)
   {vect.push_back(convert_zero_one(a[i],no));} //Converting to binary****************************************************************
     for(long int i=0;i<vect.size();i++)
     {terms.push_back(vect[i]);}

        while(!vect.empty())
        {   for(i=0;i<vect.size()-1;i++)
            {                long int c=0;
     for(j=i+1;j<vect.size();j++)
     {
     l=compare(vect[i],vect[j]); //Comparing the elements******************************************************************************
     if(l!=-1 && l!=-2)
                   {temp1.push_back(change(vect[i],l));
                   newvect2.push_back(j);
                }
         else c++;
         }
        if(c==j-i-1)
        { long int d=0;for(long int k=0;k<newvect2.size();k++)
            {
                        if(i==(newvect2[k]))
                    {d=1;break;}
                    }
        if(d==0) investigatefunction(vect[i],prime); //Calling the investigate function***************************
        }
            }
   long int d=0;
   for(long int k=0;k<newvect2.size();k++)
        {
                if(i==(newvect2[k]))
                {d=1;break;}
            }
            if(d==0)investigatefunction(vect[i],prime);
            vect.clear();
            for(long int i=0;i<temp1.size();i++)
            {
                vect.push_back(temp1[i]);
            }
            temp1.clear();                //Clearing the vectors***********************************************************************
            newvect2.clear();
        }
   vector<string>().swap(temp1),vector<string>().swap(vect);
         vector<long int>().swap(newvect2);
major=prime.size();
      minor=n;
     long int**t = new long int*[major+1];
     for(long int i=0;i<major+1;i++)
         {  t[i]=new long int[minor];              //Inserting the column elemnts into the vector**************************************
        }
    for(long int i=0;i<major+1;i++)
     {for(long int j=0;j<minor;j++)
                 t[i][j]=0;
   }
 for(long int i=0;i<major;i++)
        { long int c;
   long int n1=terms.size();
 long int m1=prime[i].length();                      //Inserting the row elemnts into the vector**************************************
       for(long int j=0;j<n1;j++)
            { c=1;
                    for(long int k=0;k<m1;k++)
           { if(prime[i][k]!='_'){if(prime[i][k]!=terms[j][k]){c=0;break;}}}
                   if(c==1)t[i][j]=1;
               }}
    for(j=0;j<minor;j++)
          {count=0;
       for(i=0;i<major;i++)
           { if(t[i][j]==1) {count++;k=i;}}
         if(count==1){wicd3.push_back(make_pair(j,k));}  //Adding pairs to wicd3 vector**********************************************
                }
        for(i=0;i<wicd3.size();i++)
        { if(t[major][wicd3[i].first]!=1)
            { ep.push_back(prime[wicd3[i].second]);  //Pushing the wicd to ep vector***********************************************
            t[wicd3[i].second][wicd3[i].first]=-1;
                 t[major][wicd3[i].first]=1;
             for(j=0;j<minor;j++)
                { if(t[wicd3[i].second][j]==1)
                {for(k=0;k<major;k++)
                    { if(t[k][j]==1)
                         t[k][j]=-1;
                }
                  t[major][j]=1;
            }}}
        }
           wicd3.clear();
  for(i=0;i<major;i++)
    { count=0;
            for(j=0;j<minor;j++)
    { if(t[i][j]==1)
                    count++;
    }
    if(count>0){wicd3.push_back(make_pair(count,i));}
   }
        sort(wicd3.begin(),wicd3.end());

        if(!wicd3.empty())
        {i=wicd3.size()-1;
            { ep.push_back(prime[wicd3[i].second]); //Pushing the prime to ep vector***********************************************
                for(j=0;j<minor;j++)
            { if(t[wicd3[i].second][j]==1)
            { for(k=0;k<major;k++)
            { if(t[k][j]==1)
             {t[k][j]=-1;}
             }
            }}}
    while(1)
    {k=1;
    for(i=0;(i<wicd3.size()-k && i>=0);i++)
    {count=0;
   for(j=0;j<minor;j++)
  { if(t[wicd3[i].second][j]==1)
   count++;
   }
        if(count>0)
      {wicd3[i].first=count;}else wicd3[i].first=0;
                }
   sort(wicd3.begin(),wicd3.end()-k);
   i=wicd3.size()-1-k;
   if(wicd3[i].first>0)
   { ep.push_back(prime[wicd3[i].second]);  //Pushing the implicants into the rp vector*********************************************
     for(j=0;j<minor;j++)
     { if(t[wicd3[i].second][j]==1)
   { for(k=0;k<major;k++)
       { if(t[k][j]==1)
       {t[k][j]=-1;}
                            }
       }}}
    else
    break;
    k++;
            }
// Pushing essential prime implicants to the vector**********************************************************************************
for(long int i=0;i<ep.size();i++)
{     vecnew.push_back(ep[i]);
    }
cout<<ep.size()<<endl;
 }
 else
{
//Operation to push the essential prime implicants************************************************************************************
for(long int i=0;i<prime.size();i++)
{     vecnew.push_back(prime[i]);
            }
cout<<prime.size()<<" "<<endl;
}
  fn.push_back(vecnew);
    }
vector<string >w;
//Converting to binary representation****************************************************************************************************
    for(long int i=0;i<pow(2,fun_num);i++)
        w.push_back(convert_zero_one(i,fun_num));
    vector<set<string> > funvect;
       for(long int i=0;i<w.size();i++)
    {  set<string> newvar;
        for(long int j=0;j<w[i].size();j++)
        {

 if(w[i][j]=='0')
     {
             for(long int k=0;k<fn[j+fun_num].size();k++)      //inserting the fns into vector******************************************
                    newvar.insert(fn[j+fun_num][k]);
            }

    else
        {
                for(long int k=0;k<fn[j].size();k++)
                    newvar.insert(fn[j][k]);
 }
}
         funvect.push_back(newvar);
    }
// Calculate set of functions having less terms****************************************************************************************
 long int min=funvect[0].size(),res=0;
    for(long int i=1;i<pow(2,fun_num);i++)
    {
        if(min>funvect[i].size())
     {
  res=i;min=funvect.size();
        }}
     vector<long int>ans;
string s=(convert_zero_one(res,fun_num));
    cout<<"PLA TABLE FORMED IS -------------------------->";

    cout<<endl;
    set <string> pla;
//Printing the table***************************************************************************************************************
  for(long int i=0;i<s.length();i++){
    if(s[i]=='0'){
      for(long int j=0;j<fn[i+fun_num].size();j++){
  pla.insert(fn[i+fun_num][j]);
                }
         }
else{
                for(long int j=0;j<fn[i].size();j++){
                    pla.insert(fn[i][j]);
                }
            }
    }//****************************************************************************************************************************
    cout<<"            Input          Output"<<endl;
    int serialno=1,ct=0;
for(auto i=pla.begin();i!=pla.end();i++){
    cout<<"     ("<<serialno<<"). value    "<<*(i)<<"    ";
    for(int x=0;x<s.length();x++){
        ct=0;
        if(s[x]=='0'){
            for(int j=0;j<fn[x+ fun_num].size();j++){
                if(*(i)==fn[x+ fun_num][j]){
                    ct++;
                }
            }
            if(ct){
                cout<<1<<" ";                    //Printing the inputs******************************************************************
            }
            else{
                cout<<0<<" ";
            }
        }
        else{
            for(int j=0;j<fn[x].size();j++){
                if(*(i)==fn[x][j]){
                    ct++;
                }
            }
            if(ct){
                cout<<1<<" ";                     //Printing the outputs*****************************************************************
            }
            else{
                cout<<0<<" ";
            }
        }
    }
    cout<<endl;
    serialno++;                                     //Incrementing the serialno*************************************************************
}
cout<<endl;
cout<<"__________________________________________________________________________________________________________________"<<endl;

    return 0;
}
