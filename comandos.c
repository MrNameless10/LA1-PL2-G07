int q(){
}

int gr(){
}

int ler(){
    FILE *fp1;char c;
    fp1= fopen ("C:\\meusficheiros \\ novoficheiro.txt", "ler");
    while(1){
        c = fgetc(fp1);
        if(c==EOF)
            break;
        else
            printf("%c", c);
    }
    fclose(fp1);
    return 0;
}

