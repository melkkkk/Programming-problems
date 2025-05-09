/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No one
//
// Name: Melinda Caringal
// login ID: mcaringa
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


/////////////////////////////////////////////////////////
/////////////// DO NOT MODIFY THIS CODE /////////////////
/////////////////////////////////////////////////////////

const int MAX_PW_LEN = 100;
const int MAX_HELP_LEN = 30;


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////// YOU MAY MAKE EDITS IN THE FOLLOWING SECTION /////////
///// DO NOT CHANGE FUNCTION SIGNATURES OF REQUIRED FUNCTIONS //////
//// INCLUDE DOCUMENTED HELPER FUNCTIONS IF ANY IN THIS SECTION ////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

const int MIN_LENGTH = 5;
const int MAX_CAPI = 90;
const int MIN_CAPI = 65;
const int MAX_NUM = 57;
const int MIN_NUM = 48;
const int MAX_LOWR = 122;
const int MIN_LOWR = 97;

// check_length(str) returns  true if str has at least the minimum length
//   required for a valid password, and false otherwise.
// requires: str is a valid string
bool check_length(const char *str) {
	if (strlen(str) >= MIN_LENGTH) {
		return true;
	}
	return false;
}


// check_capital(str) returns  true if str contains at least one capital
//   letter, and false otherwise.
// requires: str is a valid string
bool check_capital(const char *str) {
	int len = strlen(str);

	for (int i = 0; i < len; ++i) {
		if ((str[i] <= MAX_CAPI) && (str[i] >= MIN_CAPI)) {
			return true;
		}
	}

	return false;
}


// check_num(str) returns  true if str contains at least one number,
//   and false otherwise.
// requires: str is a valid string
bool check_num(const char *str) {
	int len = strlen(str);

        for (int i = 0; i < len; ++i) {
                if ((str[i] <= MAX_NUM) && (str[i] >= MIN_NUM)) {
                        return true;
                }
        }

	return false;
}


// check_symbol(str) returns  true if str contains at least one,
//   non-alphanumeric character, and false otherwise.
// requires: str is a valid string
bool check_symbol(const char *str) {
	int len = strlen(str);

        for (int i = 0; i < len; ++i) {
                if (!(((str[i] <= MAX_NUM) && (str[i] >= MIN_NUM)) ||
			((str[i] <= MAX_CAPI) && (str[i] >= MIN_CAPI)) || 
		    	((str[i] <= MAX_LOWR) && (str[i] >= MIN_LOWR)))) {
                        return true;
                }
        }

	return false;
}


// str_contains(str, fragment) returns true if str contains the sequence
//   given by fragment, and false otherwise.
// requires: str is a valid string
//           fragment is a valid string
bool str_contains(const char *str, const char *fragment) {
	int lenstr = strlen(str);
	int lenfrag = strlen(fragment);

	int correct = 0;
	for (int i = 0; i <= lenstr - lenfrag; ++i) {
		for (int j = 0; j < lenfrag; ++j) {
			if (str[i + j] != fragment[j]){
				break;
			} else {
				correct += 1;
			}
		}

		if (correct == lenfrag) {
			return true;
		} 

		correct = 0;
	}

	return false;
}


// check_positivity(str) returns true if str contains the sequence "(^_^)",
//   and false otherwise.
// requires: str is a valid string
bool check_positivity(const char *str) {
	char happi[] = "(^_^)";
	return str_contains(str, happi);
}


// check_sum(str) returns true if all digits in str have a valid sum,
//   and false otherwise.
// requires: str is a valid string
bool check_sum(const char *str) {
	int len = strlen(str);
	int sum = 0;

	for (int i = 0; i < len; ++i) {
		if ((str[i] <= MAX_NUM) && (str[i] >= MIN_NUM)) {
                        sum += (str[i] - MIN_NUM);
		}
	}
	if (sum == 25) {
		return true;
	}

	return false;
}


// check_palindrome(str) returns  true if str is a palindrome,
//   and false otherwise.
// requires: str is a valid string
bool check_palindrome(const char *str) {
	char filtered[101] = "";
	int len = strlen(str);

	for (int i = 0; i < len; ++i) {
		if (((str[i] <= MAX_LOWR) && (str[i] >= MIN_LOWR)) ||
			((str[i] <= MAX_NUM) && (str[i] >= MIN_NUM))){
			char single[2] = {str[i]};
			strcat(filtered, single);
		} 
	       
		if ((str[i] <= MAX_CAPI) && (str[i] >= MIN_CAPI)) {
			char single[2] = {(str[i] - 'A' + 'a')};
			strcat(filtered, single);
		}
	}

	int len_filter = strlen(filtered);

	for (int i = 0; i < (len_filter / 2); ++i) {
		if (filtered[i] != filtered[len_filter - i - 1]) {
			return false;
		}
	}

	return true;
}


// password_help(in_str, out_str) stores in out_str a valid password
//   containing the sequence in_str
// requires: in_str is a valid string
//           out_str points to a valid char[]
//           in_str contains only letter characters (not asserted)
// effects: mutates the char[] pointed to by out_str
void password_help(const char *in_str, char *out_str) {
	char start[] = "255A";
	char middle[] = "1";
	char end[] = "A552$(^_^)";
	char reversed[31] = "";

	int len_str = strlen(in_str);

	for (int i = 0; i < len_str; ++i) {
		reversed[i] = in_str[len_str - i - 1];
	}

	strcat (out_str, start);
	strcat (out_str, in_str);
        strcat (out_str, middle);
	strcat (out_str, reversed);
	strcat (out_str, end);	
}


/////////////////////////////////////////////////////////
/////////// DO NOT MODIFY ANY CODE BELOW THIS ///////////
/////////////////////////////////////////////////////////


// test_str(result) produces a string to be printed for a boolean test result
char* test_str(const bool result) {
	if(result) {
		return "Passed";
	} else {
		return "Failed";
	}
}


int main(void) {
	// Hard coded test harness will dictate what .in and .expect files are like
	// for .in file:
	// until the end of the file, read lines beginning with a char:
	//   c: run all checks on a candidate password
	//      followed by a string, the candidate password to check
	//   h: create a valid password from a base alphabetic string
	//      followed by an alphabetic string, which must appear in the output
	//   any other char: exit program
	// See sample .in and .expect files for examples.

	char pw[101];
	char help_str[31];
	char command = '\0';

	// read in commands
	while (scanf(" %c", &command) == 1) {
		if (command == 'c') {
			if (scanf("%100s", pw) == 1) {
				printf("Testing candidate password: %s\n", pw);
				printf("Length check: %s\n", test_str(check_length(pw)));
				printf("Capital check: %s\n", test_str(check_capital(pw)));
				printf("Number check: %s\n", test_str(check_num(pw)));
				printf("Symbol check: %s\n", test_str(check_symbol(pw)));
				printf("Digit sum check: %s\n", test_str(check_sum(pw)));
				printf("Positivity check: %s\n",
				       test_str(check_positivity(pw)));
				printf("Palindrome check: %s\n",
				       test_str(check_palindrome(pw)));
			} else {
				printf("Failed to read string.\n");
				return 0;
			}
		} else if (command == 'h') {
			if (scanf("%30s", help_str) == 1) {
				printf("Word to convert to password: %s\n", help_str);
				password_help(help_str, pw);
				printf("Resulting password: %s\n", pw);
			} else {
				printf("Failed to read string.\n");
				return 0;
			}
		} else {
			printf("Exiting.\n");
			return 0;
		}
	}
}
