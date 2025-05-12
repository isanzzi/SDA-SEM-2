#include "tree.h"

address Create_node (infoelmt info){
	address temp = (address) malloc (sizeof(nbtree));
	if (temp != NULL){
		temp->info = info;
		temp->left = NULL;
		temp->right = NULL;
		temp->parent = NULL;
	} else {
        printf ("gagal membuat node\n");
    }
	return temp;
}

void Create_tree(address *root){
	*root=NULL;
}

bool IsEmpty(address P) {
    if (P==NULL){
    	return true;
	} else {
		return false;
	}
}

void InOrder (address P){ 
    if(IsEmpty(P)){
        return;
    }

    //fs, current, current(exist nb), nb
    InOrder (P->left);
    printf ("%c", P->info);
    InOrder (P->right);
}

void ClearTree (address *root){
    if (root== NULL || *root == NULL){
        printf ("no tree\n");
    }

    if ((*root)->left != NULL){
        address temp = (*root)->left;
        (*root)->left = NULL;
        ClearTree (&temp);
    }

    if ((*root)->right != NULL){
        address temp = (*root)->right;
        (*root)->right = NULL;
        ClearTree (&temp);
    }

    free (*root);
    *root = NULL;
}

void stringtomorse(address root, char *string, char *hasil) {
    if (string == NULL || hasil == NULL) {
        printf("invalid parameter\n");
        return;
    }

    int resultIndex = 0;

    while (*string != '\0') {
        char currentChar = (char)toupper((unsigned char)*string);
        Stack top;
        createinitStack(&top);

        if (findcharintree(root, currentChar, &top)) {
            char tempCodes[50];
            int tempIndex = 0;
            
            // Pop all
            while (!StackEmpty(&top)) {
                infoelmt code;
                Pop(&top, &code);
                tempCodes[tempIndex++] = code; //insert pop ke tempcode
            }
            
            //print hasil stack tersebut ke hasil, tidak usah reverse
            //karena stack = insertawal + traversal = child-root
            //sehingga menghasilkan urutan dari root-traversal
            printf("Char '%c' Morse: ", currentChar);
            int i=0;
            while (i<tempIndex){
                hasil[resultIndex++] = tempCodes[i];
                printf("%c", tempCodes[i]);
                i++;
            }
            hasil[resultIndex++] = '/'; // pemisah kata
        }
        string++;
    }

    if (resultIndex > 0 && hasil[resultIndex - 1] == '/') {
        resultIndex--; // agar menghilangkan slash di akhir kalimat
    }

    hasil[resultIndex] = '\0';
}

bool findcharintree(address head, char target, Stack *S) {
    if (head == NULL) {
        return false;
    }
    if (head->info == target) {
        printf("[Find] Character '%c' found\n", target);
        return true;
    }
    
    if (findcharintree(head->left, target, S)) {
        Push(S, 'r');
        printf("[Find] Adding 'r' to path for '%c'\n", target);
        return true;
    }

    if (findcharintree(head->right, target, S)) {
        Push(S, 'n');
        printf("[Find] Adding 'n' to path for '%c'\n", target);
        return true;
    }

    return false;
}

void txtmorsetostring(address head) {
    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");
    if (fr == NULL || fw == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), fr) != NULL) {
        // Hilangkan newline dari buffer jika ada
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        toupperstring(buffer);
        char output[2000] = {0};
        
        stringtomorse(head, buffer, output);
        
        // Tulis ke file output dan newlinenya
        fprintf(fw, "%s\n", output);
    }
    
    fclose(fr);
    fclose(fw);
    printf("Konversi input.txt ke output.txt sukses\n");
}

void morsetostring(address root, address p, char *str, char *hasil) {
    if (*str == '\0') { //end string
        if (p != NULL && p->info != 0) {
            int len = (int) strlen(hasil);
            hasil[len] = p->info; 
            hasil[len+1] = '\0';
        }
        return;//jika diakhir string agar bisa end recur
    }
    else if (*str == '/') { //slash buat reset root dan tampilkan
        if (p != NULL && p->info != 0) {
            int len = (int) strlen(hasil);
            hasil[len] = p->info;
            hasil[len+1] = '\0';
        }
        
        // Add space and reset to root
        int len = (int) strlen(hasil);
        hasil[len+1] = '\0';
        morsetostring(root, root, str + 1, hasil); //reset root
    }
    else if (*str == 'r') {
        if (p != NULL) {
            morsetostring(root, p->left, str + 1, hasil);
        } else {
            morsetostring(root, NULL, str + 1, hasil);
        }
    }
    else if (*str == 'n') {
        if (p != NULL) {
            morsetostring(root, p->right, str + 1, hasil);
        } else {
            morsetostring(root, NULL, str + 1, hasil);
        }
    }
    else {// exception error
        morsetostring(root, p, str + 1, hasil);
    }
}

void toupperstring (char *str){
    int i=0;
    while (str[i]!= '\0'){
        str[i] = (char)toupper((unsigned char)str[i]);
        i++;
    }
}

void initialize_tree(address *root) {
    *root = Create_node (0);
    address A = Create_node('A');
    address B = Create_node('B');
    address C = Create_node('C');
    address D = Create_node('D');
    address E = Create_node('E');
    address F = Create_node('F');
    address G = Create_node('G');
    address H = Create_node('H');
    address I = Create_node('I');
    address J = Create_node('J');
    address K = Create_node('K');
    address L = Create_node('L');
    address M = Create_node('M');
    address N = Create_node('N');
    address O = Create_node('O');
    address P = Create_node('P');
    address Q = Create_node('Q');
    address R = Create_node('R');
    address S = Create_node('S');
    address T = Create_node('T');
    address U = Create_node('U');
    address V = Create_node('V');
    address W = Create_node('W');
    address X = Create_node('X');
    address Y = Create_node('Y');
    address Z = Create_node('Z');
    
    address nol = Create_node('0');
    address satu = Create_node('1');
    address dua = Create_node('2');
    address tiga = Create_node('3');
    address empat = Create_node('4');
    address lima = Create_node('5');
    address enam = Create_node('6');
    address tujuh = Create_node('7');
    address delapan = Create_node('8');
    address sembilan = Create_node('9');
    
    address space = Create_node(' ');

    (*root)->left = A;
    (*root)->right = T;
    
    A->left=B;
    B->left=C;
    C->left=D;
    D->left=E;
    G->left=H;
    J->left=K;
    M->left=N;
    N->left=O;
    Q->left=R;
    T->left=U;
    U->left=V;
    V->left=W;
    Y->left=Z;
    satu->left=dua;
    dua->left=tiga;
    lima->left=enam;
    enam->left=tujuh;

    A->right=M;
    B->right=J;
    C->right=G;
    D->right=F;
    G->right=I;
    J->right=L;
    M->right=Q;
    N->right=P;
    Q->right=S;
    T->right=satu;
    U->right=Y;
    V->right=X;
    Y->right=nol;
    satu->right=lima;
    dua->right=empat;
    lima->right=sembilan;
    enam->right=delapan;
    sembilan->right=space;
}