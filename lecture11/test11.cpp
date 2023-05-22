#include <iostream>
#include <vector>

// 화면 크기 상수
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

// 화면 버퍼 클래스
class ScreenBuffer {
private:
    char buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

public:
    void Clear() {
        for (int y = 0; y < SCREEN_HEIGHT; ++y) {
            for (int x = 0; x < SCREEN_WIDTH; ++x) {
                buffer[y][x] = ' ';
            }
        }
    }

    void SetPixel(int x, int y, char pixel) {
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            buffer[y][x] = pixel;
        }
    }

    void Render() {
        for (int y = 0; y < SCREEN_HEIGHT; ++y) {
            for (int x = 0; x < SCREEN_WIDTH; ++x) {
                std::cout << buffer[y][x];
            }
            std::cout << std::endl;
        }
    }
};

// 객체 클래스
class Object {
protected:
    int x;
    int y;

public:
    Object(int xPos, int yPos) : x(xPos), y(yPos) {}

    virtual void Render(ScreenBuffer& screenBuffer) = 0;
};

// SnakeBody 클래스 (Object를 상속)
class SnakeBody : public Object {
public:
    SnakeBody(int xPos, int yPos) : Object(xPos, yPos) {}

    void Render(ScreenBuffer& screenBuffer) override {
        // SnakeBody를 그리는 로직 구현
        screenBuffer.SetPixel(x, y, '#');
    }
};

// Scene 클래스
class Scene {
private:
    ScreenBuffer screenBuffer;
    std::vector<Object*> objects;

public:
    void AddObject(Object* object) {
        objects.push_back(object);
    }

    void ClearScreenBuf() {
        screenBuffer.Clear();
    }

    void Draw() {
        ClearScreenBuf();

        for (Object* object : objects) {
            object->Render(screenBuffer);
        }

        screenBuffer.Render();
    }
};

// 게임 루프 함수
void GameLoop() {
    Scene scene;

    SnakeBody snakeBody1(10, 5);
    SnakeBody snakeBody2(11, 5);
    SnakeBody snakeBody3(12, 5);

    scene.AddObject(&snakeBody1);
    scene.AddObject(&snakeBody2);
    scene.AddObject(&snakeBody3);

    while (true) {
        // 게임 루프 로직

        scene.Draw();

        // 프레임 간 시간 지연 등의 로직 추가 가능
    }
}

int main() {
    GameLoop();

    return 0;
}
