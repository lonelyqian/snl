#pragma once
#include "stdlib.h"

#include <stack>
#include <string.h>
#include "SNL_utl.h"

using namespace std;
class doGrammer
{
public:
    char temp_name[10];
    vector<Token> tokens;
    void Match(string str);
    TreeNode* parse();
    TreeNode* Program();
    TreeNode* ProgramHead();
    TreeNode* DeclarePart();
    TreeNode* TypeDec();
    TreeNode* TypeDeclaration();
    TreeNode* TypeDecList();
    TreeNode* TypeDecMore();
    void TypeId(TreeNode* t);
    void TypeDef(TreeNode* t);
    void BaseType(TreeNode* t);
    void StructureType(TreeNode* t);
    void ArrayType(TreeNode* t);
    void RecType(TreeNode* t);
    TreeNode* FieldDecList();
    TreeNode* FieldDecMore();
    void IdList(TreeNode* t);
    void IdMore(TreeNode* t);
    TreeNode* VarDec();
    TreeNode* VarDeclaration();
    TreeNode* VarDecList();
    TreeNode* VarDecMore();
    void VarIdList(TreeNode* t);
    void VarIdMore(TreeNode* t);
    TreeNode* ProcDec();
    TreeNode* ProcDeclaration();
    void ParamList(TreeNode* t);
    TreeNode* ParamDecList();
    TreeNode* ParamMore();
    TreeNode* Param();
    void FormList(TreeNode* t);
    void FidMore(TreeNode* t);
    TreeNode* ProcDecPart();
    TreeNode* ProcBody();
    TreeNode* ProcDecMore();
    TreeNode* ProgramBody();
    TreeNode* StmList();
    TreeNode* StmMore();
    TreeNode* Stm();
    void AssCall(TreeNode* t);
    void AssignmentRest(TreeNode* t);
    TreeNode* ConditionalStm();
    TreeNode* LoopStm();
    TreeNode* InputStm();
    TreeNode* OutputStm();
    TreeNode* ReturnStm();
    void CallStmRest(TreeNode* t);
    TreeNode* ActParamList();
    TreeNode* ActParamMore();
    TreeNode* Exp();
    TreeNode* Simple_exp();
    TreeNode* Term();
    TreeNode* Factor();
    TreeNode* Variable();
    void VarMore(TreeNode* t);
    TreeNode* FieldVar();
    void FieldVarMore(TreeNode* t);
    void ReadToken();
    bool isEndfile();
};
int pos = 0;
Token currentToken;
string currentLexType;
void doGrammer::ReadToken() {
    if (!isEndfile()) {
        currentToken.line = tokens[pos].line;
        currentToken.lex = tokens[pos].lex;
        currentToken.sem = tokens[pos].sem;
        currentLexType = lexName[tokens[pos].lex];
        pos++;
    }
}
bool doGrammer::isEndfile() {
    if (pos < tokens.size())return false;
    else return true;
}
bool Stringequal(string a, string b) {
    if (a.compare(b) == 0) {
        return true;
    }
    else {
        return false;
    }
}
void doGrammer::Match(string str) {
    if (Stringequal(currentLexType, str)) {
        ReadToken();
        //cout << currentLexType << currentToken.line << currentToken.sem << endl;
    }
    else {
        cout << currentToken.line << " " << currentLexType << endl;
        cout << "匹配错误(57)" << endl;
        exit(0);
    }
}
TreeNode* doGrammer::parse() {
    ReadToken();
    TreeNode* t = Program();
    if (!isEndfile()) {
        cout << currentToken.line << endl;
        cout << "文件提前结束错误" << endl;
        exit(0);
    }
    else
        return t;
}
TreeNode* doGrammer::Program() {
    TreeNode* t = ProgramHead();
    TreeNode* q = DeclarePart();
    TreeNode* s = ProgramBody();
    TreeNode* root = new TreeNode;
    root->nodekind = DecK;
    root->lineno = currentToken.line;
    if (t == NULL) {
        cout << currentToken.line << endl;
        cout << "程序头为空(2)" << endl;
        exit(0);
    }
    else {
        root->child[0] = t;
    }
    if (q != NULL) {
        root->child[1] = q;
    }
    if (s == NULL) {
        cout << currentToken.line << endl;
        cout << "函数体为空(2)" << endl;
    }
    else {
        root->child[2] = s;
    }
    Match("DOT");
    return root;
}
TreeNode* doGrammer::ProgramHead() {
    TreeNode* t = new TreeNode;
    t->nodekind = PheadK;
    t->lineno = currentToken.line;
    Match("PROGRAM");
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
    }
    Match("ID");
    return t;
}
TreeNode* doGrammer::DeclarePart() {
    TreeNode* typeP = new TreeNode;
    typeP->nodekind = TypeK;
    typeP->lineno = currentToken.line;
    TreeNode* tp1 = TypeDec();
    typeP->child[0] = tp1;
    TreeNode* varP = new TreeNode;
    varP->nodekind = VarK;
    varP->lineno = currentToken.line;
    TreeNode* tp2 = VarDec();
    varP->child[0] = tp2;
    TreeNode* s = ProcDec();
    if (varP == NULL) {
        if (typeP == NULL) {
            typeP = s;
        }
        else {
            typeP->sibling = s;
        }
    }
    else {
        varP->sibling = s;
        if (typeP == NULL) {
            typeP = varP;
        }
        else {
            typeP->sibling = varP;
        }
    }
    return typeP;
}
TreeNode* doGrammer::TypeDec() {
    TreeNode* t = NULL;
    if (Stringequal(currentLexType, "TYPE")) {
        t = TypeDeclaration();
    }
    else if (Stringequal(currentLexType, "VAR")) {}
    else if (Stringequal(currentLexType, "PROCEDURE")) {}
    else if (Stringequal(currentLexType, "BEGIN")) {}
    else {
        //ReadToken();
        cout << currentToken.line << endl;
        cout << "文件提前结束(5)" << endl;
        exit(0);
    }
    return t;
}
TreeNode* doGrammer::TypeDeclaration() {
    Match("TYPE");
    TreeNode* t = TypeDecList();
    if (t == NULL) {
        cout << currentToken.line << endl;
        cout << "提示信息：空值(6)" << endl;
    }
    return t;
}
TreeNode* doGrammer::TypeDecList() {
    TreeNode* t = new TreeNode;
    t->nodekind = DecK;
    t->lineno = currentToken.line;
    TypeId(t);
    Match("EQ");
    TypeDef(t);
    Match("SEMI");
    TreeNode* p = TypeDecMore();
    if (p != NULL) {
        t->sibling = p;
    }
    return t;
}
TreeNode* doGrammer::TypeDecMore() {
    TreeNode* t = NULL;
    if (Stringequal(currentLexType, "VAR")) {}
    else if (Stringequal(currentLexType, "PROCEDURE")) {}
    else if (Stringequal(currentLexType, "BEGIN")) {}
    else if (Stringequal(currentLexType, "ID")) {
        t = TypeDecList();
    }
    else {
        //ReadToken();
        cout << "文件提前结束(8)" << endl;
        exit(0);
    }
    return t;
}
void doGrammer::TypeId(TreeNode* t) {
    if (Stringequal(currentLexType, "ID") && t != NULL) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
    }
    Match("ID");
    return;
}
void doGrammer::TypeDef(TreeNode* t) {
    if (t != NULL) {
        if (Stringequal(currentLexType, "INTEGER") || Stringequal(currentLexType, "CHAR")) {
            BaseType(t);
        }
        else if (Stringequal(currentLexType, "ARRAY") || Stringequal(currentLexType, "RECORD")) {
            StructureType(t);
        }
        else if (Stringequal(currentLexType, "ID")) {
            t->kind.dec = IdK;
            //strcpy_s(t->type_name, currentToken.sem.size() + 1, currentToken.sem.c_str());
            t->type_name = currentToken.sem;
            //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
            t->name.push_back(currentToken.sem);
            t->idnum++;
            Match("ID");
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束(10)" << endl;
            exit(0);
        }
    }
    return;
}
void doGrammer::BaseType(TreeNode* t) {
    if (Stringequal(currentLexType, "INTEGER")) {
        Match("INTEGER");
        t->kind.dec = IntegerK;
    }
    else if (Stringequal(currentLexType, "CHAR")) {
        Match("CHAR");
        t->kind.dec = CharK;
    }
    else {
        ReadToken();
    }
    return;
}
void doGrammer::StructureType(TreeNode* t) {
    if (Stringequal(currentLexType, "ARRAY")) {
        ArrayType(t);
    }
    else if (Stringequal(currentLexType, "RECORD")) {
        t->kind.dec = RecordK;
        RecType(t);
    }
    else {
        ReadToken();
    }
    return;
}
void doGrammer::ArrayType(TreeNode* t) {
    Match("ARRAY");
    Match("LMIDPAREN");
    if (Stringequal(currentLexType, "INTC")) {
        t->attr.ArrayAttr.low = atoi(currentToken.sem.c_str());
    }
    Match("INTC");
    Match("UNDERRANGE");
    if (Stringequal(currentLexType, "INTC")) {
        t->attr.ArrayAttr.up = atoi(currentToken.sem.c_str());
    }
    Match("INTC");
    Match("RMIDPAREN");
    Match("OF");
    BaseType(t);
    t->attr.ArrayAttr.childtype = t->kind.dec;
    t->kind.dec = ArrayK;
    return;
}
void doGrammer::RecType(TreeNode* t) {
    Match("RECORD");
    TreeNode* p = FieldDecList();
    if (p != NULL) {
        t->child[0] = p;
    }
    else {
        cout << currentToken.line << endl;
        cout << "指针为空(14)" << endl;
        exit(0);
    }
    Match("END");
    return;
}
TreeNode* doGrammer::FieldDecList() {
    TreeNode* t = new TreeNode;
    (*t).nodekind = DecK;
    (*t).lineno = currentToken.line;
    TreeNode* p = NULL;
    if (Stringequal(currentLexType, "INTEGER") || Stringequal(currentLexType, "CHAR")) {
        BaseType(t);
        IdList(t);
        Match("SEMI");
        p = FieldDecMore();
    }
    else if (Stringequal(currentLexType, "ARRAY")) {
        ArrayType(t);
        IdList(t);
        Match("SEMI");
        p = FieldDecMore();
    }
    else {
        //ReadToken();
        cout << currentToken.line << endl;
        cout << "文件提前结束(15)" << endl;
        exit(0);
    }
    t->sibling = p;
    return t;
}
TreeNode* doGrammer::FieldDecMore() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "END")) {
        if (Stringequal(currentLexType, "INTEGER") || Stringequal(currentLexType, "CHAR") || Stringequal(currentLexType, "ARRAY")) {
            t = FieldDecList();
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（16）" << endl;
            exit(0);
        }
    }
    return t;
}
void doGrammer::IdList(TreeNode* t) {
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
    }
    Match("ID");
    IdMore(t);
    return;
}
void doGrammer::IdMore(TreeNode* t) {
    if (!Stringequal(currentLexType, "SEMI")) {
        if (Stringequal(currentLexType, "COMMA")) {
            Match("COMMA");
            IdList(t);
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（18）" << endl;
            exit(0);
        }
    }
    return;
}
TreeNode* doGrammer::VarDec() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "PROCEDURE")) {
        if (!Stringequal(currentLexType, "BEGIN")) {
            if (Stringequal(currentLexType, "VAR")) {
                t = VarDeclaration();
            }
            else {
                //ReadToken();
                cout << currentToken.line << endl;
                cout << "文件提前结束（19）" << endl;
                exit(0);
            }
        }
    }
    return t;
}
TreeNode* doGrammer::VarDeclaration() {
    Match("VAR");
    TreeNode* t = VarDecList();
    if (t == NULL) {
        cout << currentToken.line << endl;
        cout << "返回语法树为空（20）" << endl;
    }
    return t;
}
TreeNode* doGrammer::VarDecList() {
    TreeNode* t = new TreeNode;
    t->nodekind = DecK;
    t->lineno = currentToken.line;
    TreeNode* p = NULL;
    TypeDef(t);
    VarIdList(t);
    Match("SEMI");
    p = VarDecMore();
    t->sibling = p;
    return t;
}
TreeNode* doGrammer::VarDecMore() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "PROCEDURE")) {
        if (!Stringequal(currentLexType, "BEGIN")) {
            if (Stringequal(currentLexType, "INTEGER") || Stringequal(currentLexType, "CHAR") || Stringequal(currentLexType, "ARRAY") || Stringequal(currentLexType, "RECORD") || Stringequal(currentLexType, "ID")) {
                t = VarDecList();
            }
            else {
                //ReadToken();
                cout << currentToken.line << endl;
                cout << "文件提前结束（22）" << endl;
                exit(0);
            }
        }
    }
    return t;
}
void doGrammer::VarIdList(TreeNode* t) {
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
        Match("ID");
    }
    else {
        //ReadToken();
        cout << currentToken.line << endl;
        cout << "文件提前结束（23）" << endl;
        exit(0);
    }
    VarIdMore(t);
    return;
}
void doGrammer::VarIdMore(TreeNode* t) {
    if (!Stringequal(currentLexType, "SEMI")) {
        if (Stringequal(currentLexType, "COMMA")) {
            Match("COMMA");
            VarIdList(t);
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束(24)" << endl;
            exit(0);
        }
    }
    return;
}
TreeNode* doGrammer::ProcDec() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "BEGIN")) {
        if (Stringequal(currentLexType, "PROCEDURE")) {
            t = ProcDeclaration();
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（25）" << endl;
            exit(0);
        }
    }
    return t;
}
TreeNode* doGrammer::ProcDecMore()
{
    return nullptr;
}
TreeNode* doGrammer::ProcDeclaration() {
    TreeNode* t = new TreeNode;
    t->nodekind = ProcDecK;
    t->lineno = currentToken.line;
    Match("PROCEDURE");
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
        Match("ID");
    }
    Match("LPAREN");
    ParamList(t);
    Match("RPAREN");
    Match("SEMI");
    t->child[1] = ProcDecPart();
    t->child[2] = ProcBody();
    t->sibling = ProcDecMore();
    return t;
}
void doGrammer::ParamList(TreeNode* t) {
    TreeNode* p = NULL;
    if (!Stringequal(currentLexType, "RPAREN")) {
        if (Stringequal(currentLexType, "INTEGER") || Stringequal(currentLexType, "CHAR") || Stringequal(currentLexType, "ARRAY") || Stringequal(currentLexType, "RECORD") || Stringequal(currentLexType, "ID") || Stringequal(currentLexType, "VAR")) {
            p = ParamDecList();
            t->child[0] = p;
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前退出（27）" << endl;
            exit(0);
        }
    }
    return;
}
TreeNode* doGrammer::ParamDecList() {
    TreeNode* t = Param();
    TreeNode* p = ParamMore();
    if (p != NULL) {
        t->sibling = p;
    }
    return t;
}
TreeNode* doGrammer::ParamMore() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "RPAREN")) {
        if (Stringequal(currentLexType, "SEMI")) {
            Match("SEMI");
            t = ParamDecList();
            if (t == NULL) {
                cout << currentToken.line << endl;
                cout << "空值错误（29）" << endl;
                exit(0);
            }
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（29）" << endl;
            exit(0);
        }
    }
    return t;
}
TreeNode* doGrammer::Param() {
    TreeNode* t = new TreeNode;
    t->nodekind = DecK;
    t->lineno = currentToken.line;
    if (Stringequal(currentLexType, "INTEGER") || Stringequal(currentLexType, "CHAR") || Stringequal(currentLexType, "RECORD") || Stringequal(currentLexType, "ARRAY") || Stringequal(currentLexType, "ID")) {
        t->attr.ProcAttr.paramt = valparamType;
        TypeDef(t);
        FormList(t);
    }
    else if (Stringequal(currentLexType, "VAR")) {
        Match("VAR");
        t->attr.ProcAttr.paramt = varparamType;
        TypeDef(t);
        FormList(t);
    }
    else {
        //ReadToken();
        cout << currentToken.line << endl;
        cout << "文件提前结束（30）" << endl;
        exit(0);
    }
    return t;
}
void doGrammer::FormList(TreeNode* t) {
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
        Match("ID");
    }
    FidMore(t);
    return;
}
void doGrammer::FidMore(TreeNode* t) {
    if (!Stringequal(currentLexType, "SEMI")) {
        if (!Stringequal(currentLexType, "RPAREN")) {
            if (Stringequal(currentLexType, "COMMA")) {
                Match("COMMA");
                FormList(t);
            }
            else {
                //ReadToken();
                cout << currentToken.line << endl;
                cout << "文件提前结束（32）" << endl;
                exit(0);
            }
        }
    }
    return;
}
TreeNode* doGrammer::ProcDecPart() {
    TreeNode* t = DeclarePart();
    return t;
}
TreeNode* doGrammer::ProcBody() {
    TreeNode* t = ProgramBody();
    if (t == NULL) {
        cout << currentToken.line << endl;
        cout << "空值错误（34）" << endl;
        exit(0);
    }
    return t;
}
TreeNode* doGrammer::ProgramBody() {
    TreeNode* t = new TreeNode;
    t->nodekind = StmLK;
    t->lineno = currentToken.line;
    Match("BEGIN");
    t->child[0] = StmList();
    Match("END");
    return t;
}
TreeNode* doGrammer::StmList() {
    TreeNode* t = Stm();
    TreeNode* p = StmMore();
    if (p != NULL) {
        t->sibling = p;
    }
    return t;
}
TreeNode* doGrammer::StmMore() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "END")) {
        if (!Stringequal(currentLexType, "ENDWH")) {
            if (!Stringequal(currentLexType, "ELSE")) {
                if (!Stringequal(currentLexType, "FI")) {
                    if (Stringequal(currentLexType, "SEMI")) {
                        Match("SEMI");
                        t = StmList();
                    }
                    else {
                        //ReadToken();
                        cout << currentToken.line << endl;
                        cout << "文件提前结束（37）" << endl;
                        exit(0);
                    }
                }
            }

        }
    }
    return t;
}
TreeNode* doGrammer::Stm() {
    TreeNode* t = NULL;
    if (Stringequal(currentLexType, "IF")) {
        t = ConditionalStm();
    }
    else if (Stringequal(currentLexType, "WHILE")) {
        t = LoopStm();
    }
    else if (Stringequal(currentLexType, "RETURN")) {
        t = ReturnStm();
    }
    else if (Stringequal(currentLexType, "READ")) {
        t = InputStm();
    }
    else if (Stringequal(currentLexType, "WRITE")) {
        t = OutputStm();
    }
    else if (Stringequal(currentLexType, "ID")) {
        TreeNode* f = new TreeNode;
        f->nodekind = StmtK;
        f->lineno = currentToken.line;
        TreeNode* t1 = new TreeNode;
        t1->nodekind = ExpK;
        t1->lineno = currentToken.line;
        t1->kind.exp = VariK;
        t1->attr.ExpAttr.varkind = IdV;
        //strcpy_s(t1->name[t1->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t1->name.push_back(currentToken.sem);
        t1->idnum++;
        f->child[0] = t1;
        strcpy_s(temp_name, currentToken.sem.size() + 1, currentToken.sem.c_str());
        AssCall(f);
        t = f;
    }
    else {
        cout << currentToken.line << endl;
        cout << "非期望单词语法错误（38）" << endl;
        exit(0);
        ReadToken();
    }
    return t;
}
void doGrammer::AssCall(TreeNode* t) {
    Match("ID");
    if (Stringequal(currentLexType, "ASSIGN") || Stringequal(currentLexType, "LMIDPAREN") || Stringequal(currentLexType, "DOT")) {
        AssignmentRest(t);
    }
    else if (Stringequal(currentLexType, "LPAREN")) {
        CallStmRest(t);
        t->kind.stmt = CallK;
    }
    else {
        //ReadToken();
        cout << currentToken.line << endl;
        cout << "文件提前结束（39）" << endl;
        exit(0);
    }
    return;
}
void doGrammer::AssignmentRest(TreeNode* t) {
    VarMore(t->child[0]);
    Match("ASSIGN");
    t->child[1] = Exp();
    return;
}
TreeNode* doGrammer::ConditionalStm() {
    TreeNode* t = new TreeNode;
    t->nodekind = StmtK;
    t->kind.stmt = IfK;
    t->lineno = currentToken.line;
    Match("IF");
    t->child[0] = Exp();
    Match("THEN");
    t->child[1] = StmList();
    if (Stringequal(currentLexType, "ELSE")) {
        Match("ELSE");
        t->child[2] = StmList();
    }
    Match("FI");
    return t;
}
TreeNode* doGrammer::LoopStm() {
    TreeNode* t = new TreeNode;
    t->nodekind = StmtK;
    t->kind.stmt = WhileK;
    t->lineno = currentToken.line;
    Match("WHILE");
    t->child[0] = Exp();
    Match("DO");
    t->child[1] = StmList();
    Match("ENDWH");
    return t;
}
TreeNode* doGrammer::InputStm() {
    TreeNode* t = new TreeNode;
    t->nodekind = StmtK;
    t->kind.stmt = ReadK;
    t->lineno = currentToken.line;
    Match("READ");
    Match("LPAREN");
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
    }
    Match("ID");
    Match("RPAREN");
    return t;
}
TreeNode* doGrammer::OutputStm() {
    TreeNode* t = new TreeNode;
    t->nodekind = StmtK;
    t->kind.stmt = WriteK;
    t->lineno = currentToken.line;
    Match("WRITE");
    Match("LPAREN");
    t->child[0] = Exp();
    Match("RPAREN");
    return t;
}
TreeNode* doGrammer::ReturnStm() {
    TreeNode* t = new TreeNode;
    t->nodekind = StmtK;
    t->kind.stmt = ReturnK;
    t->lineno = currentToken.line;
    Match("RETURN");
    return t;
}
void doGrammer::CallStmRest(TreeNode* t) {
    Match("LPAREN");
    t->child[1] = ActParamList();
    Match("RPAREN");
}
TreeNode* doGrammer::ActParamList() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "RPAREN")) {
        if (Stringequal(currentLexType, "ID") || Stringequal(currentLexType, "INTC")) {
            t = Exp();
            if (t != NULL) {
                t->sibling = ActParamMore();
            }
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束(47)" << endl;
            exit(0);
        }
    }
    return t;
}
TreeNode* doGrammer::ActParamMore() {
    TreeNode* t = NULL;
    if (!Stringequal(currentLexType, "RPAREN")) {
        if (Stringequal(currentLexType, "COMMA")) {
            Match("COMMA");
            t = ActParamList();
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（48）" << endl;
            exit(0);
        }
    }
    return t;
}
TreeNode* doGrammer::Exp() {
    TreeNode* t = Simple_exp();
    if (Stringequal(currentLexType, "LT") || Stringequal(currentLexType, "EQ")) {
        TreeNode* p = new TreeNode;
        p->nodekind = ExpK;
        p->kind.exp = OpK;
        p->lineno = currentToken.line;
        p->child[0] = t;
        p->attr.ExpAttr.op = currentToken.lex;
        t = p;
        if (currentLexType == "LT") {
            Match("LT");
        }
        else if (currentLexType == "EQ") {
            Match("EQ");
        }
        if (t != NULL) {
            t->child[1] = Simple_exp();
        }
    }
    return t;
}
TreeNode* doGrammer::Simple_exp() {
    TreeNode* t = Term();
    while (Stringequal(currentLexType, "PLUS") || Stringequal(currentLexType, "MINUS")) {
        TreeNode* p = new TreeNode;
        p->nodekind = ExpK;
        p->lineno = currentToken.line;
        p->child[0] = t;
        p->kind.exp = OpK;
        p->attr.ExpAttr.op = currentToken.lex;
        t = p;
        Match(currentLexType);
        t->child[1] = Term();
    }
    return t;
}
TreeNode* doGrammer::Term() {
    TreeNode* t = Factor();
    while (Stringequal(currentLexType, "TIMES") || Stringequal(currentLexType, "OVER")) {
        TreeNode* p = new TreeNode;
        p->nodekind = ExpK;
        p->lineno = currentToken.line;
        p->child[0] = t;
        p->kind.exp = OpK;
        p->attr.ExpAttr.op = currentToken.lex;
        t = p;
        Match(currentLexType);
        t->child[1] = Factor();
    }
    return t;
}
TreeNode* doGrammer::Factor() {
    TreeNode* t = NULL;
    if (Stringequal(currentLexType, "INTC")) {
        t = new TreeNode();
        t->lineno = currentToken.line;
        t->nodekind = ExpK;
        t->kind.exp = ConstK;
        t->attr.ExpAttr.val = stoi(currentToken.sem);
        Match("INTC");
    }
    else if (Stringequal(currentLexType, "ID")) {
        t = Variable();
    }
    else if (Stringequal(currentLexType, "LPAREN")) {
        Match("LPAREN");
        t = Exp();
        Match("RPAREN");
    }
    else {
        cout << currentToken.line << endl;
        cout << "非期望单词（52）" << endl;
        exit(0);
        ReadToken();
    }
    return t;
}
TreeNode* doGrammer::Variable() {
    TreeNode* t = new TreeNode();
    t->nodekind = ExpK;
    t->kind.exp = VariK;
    t->lineno = currentToken.line;
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
        Match("ID");
        VarMore(t);
    }
    return t;
}
void doGrammer::VarMore(TreeNode* t) {
    if (!Stringequal(currentLexType, "ASSIGN") && !Stringequal(currentLexType, "TIMES") && !Stringequal(currentLexType, "EQ") && !Stringequal(currentLexType, "LT") && !Stringequal(currentLexType, "PLUS") && !Stringequal(currentLexType, "MINUS") && !Stringequal(currentLexType, "OVER") && !Stringequal(currentLexType, "RPAREN") && !Stringequal(currentLexType, "SEMI")
        && !Stringequal(currentLexType, "COMMA") && !Stringequal(currentLexType, "THEN") && !Stringequal(currentLexType, "RMIDPAREN") && !Stringequal(currentLexType, "ELSE") && !Stringequal(currentLexType, "FI") && !Stringequal(currentLexType, "DO") && !Stringequal(currentLexType, "ENDWH") && !Stringequal(currentLexType, "END")) {
        if (Stringequal(currentLexType, "LMIDPAREN")) {
            Match("LMIDPAREN");
            t->child[0] = Exp();
            t->attr.ExpAttr.varkind = ArrayMembV;
            (*(*t).child[0]).attr.ExpAttr.varkind = IdV;
            Match("RMIDPAREN");
        }
        else if (Stringequal(currentLexType, "DOT")) {
            Match("DOT");
            t->child[0] = FieldVar();
            t->attr.ExpAttr.varkind = FieldMembV;
            (*(*t).child[0]).attr.ExpAttr.varkind = IdV;
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（54）" << endl;
            exit(0);
        }
    }
}
TreeNode* doGrammer::FieldVar() {
    TreeNode* t = new TreeNode();
    t->nodekind = ExpK;
    t->kind.exp = VariK;
    t->lineno = currentToken.line;
    if (Stringequal(currentLexType, "ID")) {
        //strcpy_s(t->name[t->idnum], currentToken.sem.size() + 1, currentToken.sem.c_str());
        t->name.push_back(currentToken.sem);
        t->idnum++;
        Match("ID");
        FieldVarMore(t);
    }
    return t;
}
void doGrammer::FieldVarMore(TreeNode* t) {
    if (!Stringequal(currentLexType, "ASSIGN") && !Stringequal(currentLexType, "TIMES") && !Stringequal(currentLexType, "EQ") && !Stringequal(currentLexType, "LT") && !Stringequal(currentLexType, "PLUS") && !Stringequal(currentLexType, "MINUS") && !Stringequal(currentLexType, "OVER") && !Stringequal(currentLexType, "RPAREN") && !Stringequal(currentLexType, "SEMI")
        && !Stringequal(currentLexType, "COMMA") && !Stringequal(currentLexType, "THEN") && !Stringequal(currentLexType, "RMIDPAREN") && !Stringequal(currentLexType, "ELSE") && !Stringequal(currentLexType, "FI") && !Stringequal(currentLexType, "DO") && !Stringequal(currentLexType, "ENDWH") && !Stringequal(currentLexType, "END")) {
        if (Stringequal(currentLexType, "LMIDPAREN")) {
            Match("LMIDPAREN");
            t->child[0] = Exp();
            (*(*t).child[0]).attr.ExpAttr.varkind = ArrayMembV;
            Match("RMIDPAREN");
        }
        else {
            //ReadToken();
            cout << currentToken.line << endl;
            cout << "文件提前结束（56）" << endl;
            exit(0);
        }
    }
}



