/*
请实现一个函数，
将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
        int blank_num = 0;
        int old_length = 0;
        int i = 0;

        while (str[i] != '\0') {
        	if (str[i] == ' ') {
        		++blank_num;
        	}

        	++old_length;
        	++i;
        }

        ++old_length; // 包括最后一个字符'\0'

        int new_length = old_length + 2 * blank_num;
        int index_1 = old_length - 1;
        int index_2 = new_length - 1;
        
        //当index_2 == index_1 的时候，说明前面没有空格了
        while (index_1 >= 0 && index_2 > index_1) {
            if (str[index_1] == ' ') {
            	str[index_2--] = '0';
            	str[index_2--] = '2';
            	str[index_2--] = '%';
            }
            else {
                str[index_2--] = str[index_1];
            }

            --index_1;
        }
	}
};