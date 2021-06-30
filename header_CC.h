#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void random_tile();
int result(int error_code);//the function to print actual shit to stderr
int assign_val(int value,int x,int y);// returns appropriate error code
void move_perform(string* oper,string* dir); 
int name_setter(string* name,int x,int y);
int query_value(int x,int y);
#define OPERATION 1 //add sub assign value
#define DIRECTION 2 //up down
#define OTHERS 3 // is in VAR to
#define IDENTIFIER 4
#define NUMBER 5
#define FULLSTOP 6
#define COMMA 7
#define OUT_OF_BOUNDS 8
#define SUCCESS 0
#define FAILURE 10
