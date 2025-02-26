#include "CSVReader.h"
#include "SchoolList.h"
//TO DO: ADD A POINTER TO THE NEXT ITEM IN THE LINKED LIST
   //Load data and insert each school into the linked list.
   /*Loads the CSV file.
   Inserts all school records into the linked list.
   Allows the user to search for a school by name.
   Allows the user to delete a school by name.
   Displays the list of remaining schools. */
int main() {
   //get data from csv
   string fileName = "Illinois_Peoria_Schools.csv";
   vector<vector<string>> data;
   CSVReader reader;
   data = reader.readCSV(fileName);

   //write data into schoolList
   SchoolList list;
   for(int i = 1; i < data.size(); i++)
   {
      School* theSchool = new School(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], NULL);
      list.insertLast(theSchool);
   }

   //print data and test
   list.display();
   cout << endl;
   list.findByName("CALVIN COOLIDGE MIDDLE SCHOOL");
   list.deleteByName("SEAPCO RISE");
   list.deleteByName("CALVIN COOLIDGE MIDDLE SCHOOL");
   list.findByName("CALVIN COOLIDGE MIDDLE SCHOOL");

   return 0;
}
