/*In Tirana there are M pharmacies whose names are given in array PHARMACY. N medication, you can find in these pharamacies, were taken
 into consideration. For each of these medications value (in LEK) is kept in array VALUE. The two dimensional array QUANTITY with M rows and N columnsshows the
 quanities sold during the last monthfor each medication on each pharmacy. Based on these data:
	a.Declare and initialize arrays,read unknown values from the user.
	b.What is the total value (in LEK) of all pharmacies examined?
	c.Who is the pharmacy with highest number of medicines sold? "use MAXIMUM ()" 
	d.Is there an item that has a value below 10,000 LEK? If so is it the only one ? Use void CONTROL(...)function to perform the actions.
	e.Is there any medicament that is available in only one pharmacy? */

#include <iostream>
using namespace std;
//returns the index of pharmacy that has sold the highest units
int MAXIMUM(int QUANTITY[][10000], int rows, int cols){
    //index it's store index of pharmacy that sold the highest units
    //max_sold_units it's store max sold units
    int index,max_sold_units=0;
    
    //iterating rows
    for(int i=0; i < rows; i++){
        int sold_units = 0;
        //iterating columns
        for (int j = 0; j<cols; j++)
        sold_units += QUANTITY[i][j];
        
        //found max sold units
        if(max_sold_units<sold_units){
            max_sold_units = sold_units;
            index=1;
        }
        
    }
    return index;
}

// print number of items that have value < 10000 
void CONTROL(int VALUE[], int size){
    int count = 0; // store count of items that have value < 10000
    //iterating value array 
    for(int i=0; i<size; i++){
        //found an item that has value < 10000
        if(VALUE[i] < 10000)
        count++;
    }
    cout<<"\nNumber of items that have value < 10000 "<<count;
}

int main(){
    //ans (a)
    int m, n; // m ==> number of pharmacies, n ==> number of medications
    cout<<"Enter number of pharmacies: ";
    cin>>m;
    string PHARMACY[m]; // to store pharmacy names
    
    //taking pharmacy names as input
    for(int i=0; i<m;i++)
    cin>>PHARMACY[i];
    
    cout<<"\nEnter number of medications:";
    cin>>n;
    cout<<"\nEnter value (in LEK) for "<<n<<" medications\n";
    
    int VALUE[n] = {0};// to store value of medications
    for (int i = 0; i<n; i++)
    cin>>VALUE[i];
    
    cout<<"\nEnter quantity\n";
    int QUANTITY[m][10000]; //to store quantity of each medication
    
    //taking input for QUANTITY
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
        cin>>QUANTITY[i][j];
    }
    
    //ans(b)
    int total_value = 0; //to store value of all medications in all pharmacies
    //iterating rows
    for (int i=0; i<m; i++){
        //iterating columns
        for(int j=0; j<n; j++){
            total_value += QUANTITY[i][j]*VALUE[j];
        }
    }
    
    //ans(c)
    int index = MAXIMUM(QUANTITY, m, n); // returns index of the pharmacy that has sold the highest number of medicines
    cout<<"\nPharmacy with the highest number of medicines sold: "<<PHARMACY[index];
    
    //ans(d)
    CONTROL(VALUE, n);
    //ans(e)
    int count2 = 0;// to store count of medications that are available at only one pharmacy
    //iterating rows
    for(int i = 0; i<n; i++ ){
        int count=0;// to store count of current medications
        //iterating rows
        for(int j=0; j<m; j++){
        if(QUANTITY[i][j] == 0)
        count++;
    }
    if(count == m-1)
    count2++;
    }
    cout<<"\nCount of medications that are available in only one pharmacy \n"<<count2;
    return 0;
}
    
    
    

