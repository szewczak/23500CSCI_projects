void populateCmList(List<CourseMember*>& cm_list, std::string input_file);
// Adapt this function from Projects1C. If you successfully did this in Project1C you can
// skip to the next page. If you are still struggling with reading input from a file here is
// some pseudocode:
// Include fstream
// Instantiate an ifstream object (say in_stream) and open it with
// input_file
// If in_stream fail
// output an error message that says something like “cannot
// read from input_file” // it is helpful to output the name
// of the actual file but not necessary
// Else{
// while it is not in_stream end of file{
// getline of in_stream up to a ‘,’ character into an int
// id variable by doing some string-to-int conversion
// getline of in_stream up to a ‘,’ character into a
// string first_name variable
// getline of in_stream up to a ‘,’ character into a
// string last_name variable
// getline of in_stream up to a ‘\n’ character into a
// string title variable
// If it is not in_stream end of file
// Trim the \n character off the end of title
// (string::pop_back())
// call addMemberToList() with the parameters just read
// from the file
// }//end while
// }//end else
// close in_stream