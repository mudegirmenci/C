#include<stdio.h>
#include<ctype.h>
#include<string.h>

void justifytext ( char *mytext, int width);
void justifyline ( char *line, int linewidth );
 
void main() {
     
    char sstr[] = "  ModelSim provides an Integrated Debug "
        "Environment that facilitates efficient design debug "
        "for SoC and FPGA based designs. This GUI has continuously "
        "evolved to include new windows and support for new languages. "
        "This application note aims to give an introduction to the "
        "ModelSim 6.0 debug environment. This environment is "
        "trilingual supporting designs based on VHDL, Verilog "
        "(all standards including SystemVerilog, Verilog 2001 "
        "and Verilog 1995), and SystemC. Subsequent releases of"
        " ModelSim will enable even more debug capabilities "
        "supporting higher levels of abstractions for verification"
        " and modeling in SystemVerilog and SystemC. In ModelSim"
        " 6.0, the GUI has been enhanced and is based on Multiple"
        " Document Interface (MDI) layout standard. In addition, "
        "the debug windows have been re-organized in such a way as"
        " to display design data and simulation results in an intuitive manner.";
 
int twid;
    int slen = 0;
     
    slen = strlen(sstr); // Length of the input string
     
    printf("\nLength of your text : %d\n", slen);
 
    printf("Enter text width :");
    scanf("%d",&twid);
    printf("\nText Width %d\n",twid);
 
    justifytext ( sstr, twid );
     
    printf ("\n\n");
}
 
void justifytext ( char *mytext, int width){
     
    char temp[100];//a string array for calling my second function
    int i,j, currenti, counter = 0;
 
    for ( i = 0; isspace(mytext[i]); i++ );        //if there is any space at the
    memmove ( mytext, &mytext[i], strlen(mytext) );//beginning of the text, DELETED.
     
    i = 0; 
    while (  counter < (int)strlen(mytext) ){//I choose such a control-loop, because I try
                                             //some other ways and this is most trustable.
         
        for ( i, j = 0; j < width; i++, j++ ){//finding each parts of text to justify
            temp[j] = mytext[i];
        }      
     
        for ( i ; !(isspace(mytext[i])); i--, j-- );//I cannot sperate any word,
                                                    //looking for spaces
        currenti = i;                               //I will use it to start the next line
     
        for ( i; isspace(mytext[i]); i--, j-- );//This makes part of array suitable
                                                //for my second function.
        counter = i; //for controlling loop     //my second function works for only
                                                //strings that do not have spaces
                                                //neither at the begining nor at the end.
 
        for ( ++j ; j < 100; j++ ) // only temp[++j] = '\0' is enough without for loop
            temp[j] = '\0';        // but this makes me relax
 
        justifyline ( temp, width );
 
        i = currenti + 1;    // this is where I start to sperate next time
         
    }
}
 
void justifyline ( char *line, int linewidth )
{
    char *temp;   // it for usage of strtok function
    int i, j, spaces = 0, spacestoshare=0, equalshare=0, extras=0;
 
    for ( i = 0; line[i] != '\0'; i++ ){  //counting spaces. Also this means likely
                                          //how many words there
 
        if ( isspace ( line[i] ) ){
            spaces++;
        }
    }
 
    spacestoshare = linewidth - strlen(line);
 
    if ( spaces == 0 ){
        equalshare = spacestoshare+spaces; //if spaces zero, there is only a word means
        extras = 0;                        // I put all my spaces after the word. No extras
    }
 
    else {
        equalshare = (spacestoshare+spaces)/spaces;//How many spaces I will put between
                                                   //each word in equal
        extras = spacestoshare % spaces;           //Extra spaces to put
    }
     
    for ( temp = strtok ( line, " " ); temp != NULL; temp = strtok ( NULL, " ") ){ //takes
                                                                     //each word sperately
 
        printf ("%s", temp); //first write one word
 
        for ( j = 0; j < equalshare; j++ ) { // add spaces after the word
            putchar (' ');
        }
         
        if ( extras != 0 ){ // if there is extra
            putchar (' ');  //also add them
            extras --;
        }
     
    }
    putchar ('\n');
}
