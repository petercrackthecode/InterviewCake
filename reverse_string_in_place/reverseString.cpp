// link: https://www.interviewcake.com/question/cpp/reverse-string-in-place?course=fc1&section=array-and-string-manipulation
void reverseString(std::string & s)
{
  int stringLength {static_cast<int>(s.length())}, midPosition = stringLength / 2;
  for (int index = 0; index < midPosition; ++index)
    {
      char temp = s[index];
      s[index] = s[stringLength - 1 - index];
      s[stringLength - 1 - index] = temp;
    }
}