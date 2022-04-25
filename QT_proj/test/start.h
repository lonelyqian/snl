#ifndef START_H
#define START_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SNL_ll1.h"
#include "SNL_re.h"
#include "SENL.h"
using namespace std;
int show_text = 1;
int show_lnl = 1;
int show_snl = 1;
bool lnl_is_right = true;
bool snl_is_right = true;

string start(string strdata, string &errs, string &errt1)
{
    state = s0;
    s = "";//存储当前处理的token
    sw2 = "";
    l = 0;
    sw = 0;
    err = "";
    errt = "";
    lineno = 0;
    cout << "——————词法分析开始——————" << endl;
    err += "——————词法分析开始——————\n";
    sw2 = strdata;
    ch = sw2[0];
    l = sw2.size();
    Tokens tokenlist = Tokens();
    if (!tokenlist.f())
    {
        err += "在第"; err += to_string(tokenlist.line); err += "行词法分析错误\n";
        err += "——————词法分析结束——————\n";
        errt1 = errt;
        return err;

    }
    else {
        errs +="第i个token\tLex信息\t\tLine信息\t\tSem信息\n";
        for (int i = 0; i < tokenlist.tokens.size(); i++)
        {

            errs += to_string(i); errs +="\t\t";
            errs += lexName[tokenlist.tokens[i].lex];
            if (lexName[tokenlist.tokens[i].lex].size() < 8 && tokenlist.tokens[i].lex != LexType::PROGRAM)
            {
                errs += "\t\t";
            }
            else
            {
                errs += "\t";
            }
            errs += to_string(tokenlist.tokens[i].line) + "\t\t" + tokenlist.tokens[i].sem + '\n';
        }
        //cout << "what\n";
    }
    err += "——————词法分析结束——————\n\n";

    //语法部分




    SNL snl;
    err += "——————ll1语法分析开始——————\n";
    snl.tokens = tokenlist.tokens;
    snl.ggroot = snl.create_tree();
    if (!snl.snlcheck)
    {
        err += "——————ll1语法分析出错——————\n";
        errt1 = errt;
        return err;
    }
    if(show_snl)
    {
        show_SNLtree(snl.ggroot,0, false);
    }

      err += "——————ll1语法分析结束——————\n\n";


//    doGrammer dg;
//    err += "——————re语法分析开始——————\n";
//    dg.tokens = tokenlist.tokens;
//    dg.parse();
//    err += "——————re语法分析结束——————\n\n";



    //语义部分
    SENL senl;
    err += "——————语义分析开始——————\n";
    senl.Analyze(snl.ggroot);
    err += "——————语义分析结束——————\n";
    errt1 = errt;
    return err;
}
#endif // START_H
