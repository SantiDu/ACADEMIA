bool f(int &x);
bool f(int x);
bool f(const int &x);  // pass by reference but won't allow the function to modify the original data in the calling function.