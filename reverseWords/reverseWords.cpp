// link: https://www.interviewcake.com/question/cpp/reverse-words?course=fc1&section=array-and-string-manipulation
void reverseString (std::string & s);

void reverseWords(string& message)
{
    // decode the message by reversing the words
    reverseString(message);
    int substrStart{0},
        substrLength{0},
        stringLength= message.length(); // 'abc ade'
        
    for (int index= 0; index < stringLength; ++index) {
        if (message[index] == ' ' && index != stringLength - 1) {
            substrLength= index - substrStart;
            std::string substring= message.substr(substrStart, substrLength);
            reverseString(substring);
            message.replace(substrStart, substrLength, substring);
            
            substrStart= index + 1;
            substrLength= 0;
        }
        else if (index == stringLength - 1) {
            substrLength= index - substrStart + 1;
            std::string substring= message.substr(substrStart, substrLength);
            reverseString(substring);
            message.replace(substrStart, substrLength, substring);
        }
        
        ++substrLength;
    }
}

void reverseString (std::string & s)
{
  int stringLength {static_cast<int>(s.length())}, midPosition = stringLength / 2;
  for (int index = 0; index < midPosition; ++index)
    {
      char temp = s[index];
      s[index] = s[stringLength - 1 - index];
      s[stringLength - 1 - index] = temp;
    }
}