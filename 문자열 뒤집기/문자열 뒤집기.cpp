#include <stdio.h>
#include <string.h>

// �ܾ ������ �Լ�
// start: �ܾ��� ���� ��ġ�� ����Ű�� ������
// end: �ܾ��� �� ��ġ�� ����Ű�� ������
void reverseWord(char* start, char* end) 
{
    char temp; // ���� ��ȯ�� ���� �ӽ� ����

    // ���� �����Ͱ� �� �����ͺ��� ���� ���� �ݺ�
    while (start < end) 
    {
        temp = *start;   // ���� ��ġ�� ���ڸ� �ӽ� ������ ����
        *start = *end;   // �� ��ġ�� ���ڸ� ���� ��ġ�� �̵�
        *end = temp;     // �ӽ� ������ ����� ���ڸ� �� ��ġ�� �̵�
        start++;         // ���� �����͸� ���� ���ڷ� �̵�
        end--;           // �� �����͸� ���� ���ڷ� �̵�
    }
}

int main()
{
    char input[100]; // ����ڷκ��� �Է¹��� ���ڿ��� ������ �迭 (�ִ� 99�� + null ����)

    printf("Enter a string: "); 
   
    fgets(input, sizeof(input), stdin); // ���ڿ��� �Է¹���

    // �Է¹��� ���ڿ��� ���Ե� ���� ����('\n')�� ã�� �̸� null ����('\0')�� ��ü
    // strcspn �Լ��� ù ��° �Ű��������� �� ��° �Ű������� �ִ� ���� �� ó������ �����ϴ� ��ġ�� ��ȯ
    input[strcspn(input, "\n")] = '\0';

    int length = strlen(input); //���ڿ��� ���̸� int ���·� ����
    int start = 0; // ���� �ܾ��� ���� �ε����� ����Ű�� ����

    // ���ڿ��� ��� ���ڿ� ���� �ݺ�
    for (int i = 0; i <= length; i++) 
    {
        // ���� ���ڰ� �����̰ų� ���ڿ��� ���� ��� �ܾ��� ������ ����
        if (input[i] == ' ' || input[i] == '\0') 
        {
            // �ܾ��� ���۰� ���� ����Ű�� �����͸� reverseWord �Լ��� �����Ͽ� �ܾ� ������
            reverseWord(&input[start], &input[i - 1]);
            start = i + 1; // ���� �ܾ��� ���� �ε����� ����
        }
    }

    
    printf("Reversed words: \"%s\"\n", input); // ���� ���ڿ��� ���

    return 0; 
}