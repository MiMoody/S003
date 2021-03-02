
#include <iostream>

int main()
{
    char str[256];
    char s[256];
    int First; // с какого индекса удаляем
    int Len ; // длина удаления
    int counters;
    char f[] = "%s";
    char fd[] = "%d";
    std::cout << "Enter your string:";
    char outStr1[256] = "Enter the index you want to start deleting from: ";
    char outStr2[256] = "Enter the length of the deletion: ";

    __asm
    {
        lea esi, str

        push esi

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, outStr1

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, First

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8
        
        lea ebx, outStr2

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, Len

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ecx, fd
        mov ecx, -1
        dec esi

        push edx
        mov edx, First

        lea ebx, str
        push ebx
        dec ebx

            LengthStr :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz LengthStr
            push ecx

            StartDelete :
        cmp First, 0
            jge LengthDelete
            
            mov First,0

            LengthDelete :
        cmp Len, 0
            jl StrNoChange

            FirstBiggerLength :
        cmp First, ecx
            jg StrNoChange

                add esp, 8
                mov counters,ecx
                mov ecx, 0
                dec esi

                lea esi, [str]
                lea edi, [s]
                push edi

                mov edx, First

                cmp edx, 1
                jl AddLength

             StartWrite :
            inc ecx
                lodsb
                stosb
                cmp ecx, edx
                jne StartWrite

             AddLength :
            add edx, Len
            mov eax,counters
            cmp edx, eax
            jbe EndWrite
            mov edx, eax
            
                EndWrite :
            inc esi
                inc ecx
                cmp ecx, edx
                jne EndWrite

             ContinueEndWrite :
                lodsb
                stosb
                cmp al, 0
                jnz ContinueEndWrite

                jmp End
              


            StrNoChange :
            add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [str]
            lea edi, [s]
            push edi

            ContinueNoChange :
                lodsb
                stosb
                cmp al, 0
                jnz ContinueNoChange

                End:
                pop edi
                pop esi
    }
    std::cout << "Your line: ";
    std::cout << s;
}

