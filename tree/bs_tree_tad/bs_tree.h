typedef struct reg_no tipo_no;
typedef tipo_no **tipo_arvore;

tipo_no** criar_arvore();
void incluir(tipo_no **sub_raiz, int dado);
void listar_pre_ordem(tipo_no **sub_raiz);
void listar_em_ordem(tipo_no **sub_raiz);
void listar_pos_ordem(tipo_no **sub_raiz);
int excluir_maior(tipo_no **sub_raiz);
void excluir(tipo_no **sub_raiz, int dado);
