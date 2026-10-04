bool checkValidString(char* s) {
    int min_open = 0;
    int max_open = 0;
    
    // Iterate through the string until the null terminator
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            min_open++;
            max_open++;
        } else if (s[i] == ')') {
            min_open--;
            max_open--;
        } else { // s[i] == '*'
            min_open--;
            max_open++;
        }
        
        // If max_open is negative, we have too many ')'
        if (max_open < 0) {
            return false;
        }
        
        // min_open can't be negative; reset to 0 if we treated too many '*' as ')'
        if (min_open < 0) {
            min_open = 0;
        }
    }
    
    // Valid if it's possible to have exactly 0 open left parentheses
    return min_open == 0;

}