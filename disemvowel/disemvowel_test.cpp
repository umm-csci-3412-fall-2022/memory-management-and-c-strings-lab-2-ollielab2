#include <gtest/gtest.h>

#include "disemvowel.h"
char*temp;
TEST(Disemvowel, HandleEmptyString) {
  temp=disemvowel((char*) "");
  ASSERT_STREQ("", temp);
  free(temp);
}

TEST(Disemvowel, HandleNoVowels) {
	 temp=disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst",temp);
  free(temp);
}

TEST(Disemvowel, HandleOnlyVowels) {
	temp =  disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("",temp);
  free(temp);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
	 temp=disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",temp);
  free(temp);
}

TEST(Disemvowel, HandlePunctuation) {
	temp= disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!",temp);
  free(temp);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  temp=disemvowel(str);
  ASSERT_STREQ("xyz",temp);

  free(str);
  free(temp);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
