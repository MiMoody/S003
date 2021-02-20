
#include <iostream>

int main()
{
    char str[] = "Hello,World";
    char s[256];
    int First = 2; // с какого индекса удаляем
    int Len = 3; // длина удаления
    char f[] = "%s";
    __asm
    {
        lea esi, str
        lea ecx, f
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
        cmp First, 1
            jl StrNoChange

            LengthDelete :
        cmp Len, 1
            jl StrNoChange

            FirstBiggerLength :
        cmp First, ecx
            jg StrNoChange

            add edx, Len

            CheckLengthDelete :
            add ecx, 1
            cmp edx, ecx
            jg StrNoChange

                add esp, 8
                mov ecx, 1
                dec esi

                lea esi, [str]
                lea edi, [s]
                push edi

                mov edx, First

                cmp edx, 2
                jl AddLength

             StartWrite :
            inc ecx
                lodsb
                stosb
                cmp ecx, edx
                jne StartWrite

             AddLength :
            add edx, Len
            
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
    std::cout << s;
}

