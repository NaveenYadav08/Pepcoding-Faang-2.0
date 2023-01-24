https://www.lintcode.com/problem/660/

int read4(char *buf4);

class Solution {


  private:

  char* buf4 = new char[4];
  int i4 = 0;  // buf4's index
  int n4 = 0;  // buf4's size

   public:

  int read(char* buf, int n) {
    int i = 0;  // buf's index

    while (i < n) {

      if (i4 == n4) {      // All characters in buf4 are consumed
        i4 = 0;            // Reset buf4's index
        n4 = read4(buf4);  // Read 4 (or less) chars from file to buf4
        if (n4 == 0)       // Reach the EOF
          return i;
      }
      buf[i++] = buf4[i4++];

    }

    return n;
  }


};
