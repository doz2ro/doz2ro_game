#include <iostream>
#include <vector>
#include <string>

namespace MuSoeun
{

class Scene // 와일문 안에 창 띄어논거 작업
{
    int width;
    int height;
    std::vector <Object> objList;

   // screenBuf[width + (width * height)];

    char * screenBuf;
    
    void InitScreenBuf()
    {
        screenBuf = new char[(width+1) * (height+5)];

        for(int i; i<height; i++)
        {
            screenBuf[(width+1) * (height+5) * i -1] = '\n';
        }
        screenBuf[(width+1) * (height-1)-1] = '\0';
    }
    void ReleaseScreenBuf()
    {
        if (screenBuf != nullptr)
        {
            delete(screenBuf);
        }
    }
    void DrawScreenBuf()
    {
        std::cout << screenBuf;
    }
};

class Object //화면을 그리는 작업
{
    void Render()
    {

    }
};
class Component //Unity MonoBehavior
{
    void Start()
    {

    }
    void Update()
    {   

    }
};

}
int main()
{
    
}
