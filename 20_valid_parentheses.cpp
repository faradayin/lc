bool isValid(string s)
{
    stack<char> paren;
    for(auto c: s)
    {
        switch(c)
        {
            case '(':
            case '[':
            case '{': paren.push(c); break;
            case ')': if(paren.empty() || paren.top() != '(') return false; else paren.pop(); break;//调用空栈 top()是未定义行为
            case ']': if(paren.empty() || paren.top() != '[') return false; else paren.pop(); break;
            case '}': if(paren.empty() || paren.top() != '{') return false; else paren.pop(); break;
            default: ;


            
            
        }
        
    }
    return paren.empty();
}