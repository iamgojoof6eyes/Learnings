#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <queue>
#include <cmath>
#include <thread>
#include <chrono>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

const int ROWS = 21;  // Should be odd for maze
const int COLS = 31;  // Should be odd for maze
const int CELL_SIZE = 30;
const int WIDTH = COLS * CELL_SIZE;
const int HEIGHT = ROWS * CELL_SIZE;

enum CellType { EMPTY, WALL, START, END, PATH, VISITED };

struct Node {
    int x, y, g, h;
    Node* parent;
    Node(int _x, int _y, int _g, int _h, Node* _p = nullptr)
        : x(_x), y(_y), g(_g), h(_h), parent(_p) {}
    int f() const { return g + h; }
};

struct Compare {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f(); // lower f() = higher priority
    }
};

vector<vector<CellType>> grid(ROWS, vector<CellType>(COLS, WALL));

bool isInBounds(int x, int y) {
    return x > 0 && x < ROWS - 1 && y > 0 && y < COLS - 1;
}

vector<pair<int, int>> getUnvisitedNeighbors(int x, int y) {
    vector<pair<int, int>> neighbors;
    if (isInBounds(x + 2, y) && grid[x + 2][y] == WALL)
        neighbors.emplace_back(x + 2, y);
    if (isInBounds(x - 2, y) && grid[x - 2][y] == WALL)
        neighbors.emplace_back(x - 2, y);
    if (isInBounds(x, y + 2) && grid[x][y + 2] == WALL)
        neighbors.emplace_back(x, y + 2);
    if (isInBounds(x, y - 2) && grid[x][y - 2] == WALL)
        neighbors.emplace_back(x, y - 2);
    return neighbors;
}

void generateMaze(int startX, int startY) {
    srand(static_cast<unsigned>(time(nullptr)));
    stack<pair<int, int>> s;
    grid[startX][startY] = EMPTY;
    s.push({startX, startY});

    while (!s.empty()) {
        auto [x, y] = s.top();
        auto neighbors = getUnvisitedNeighbors(x, y);
        if (!neighbors.empty()) {
            auto [nx, ny] = neighbors[rand() % neighbors.size()];
            grid[nx][ny] = EMPTY;
            grid[(x + nx) / 2][(y + ny) / 2] = EMPTY;
            s.push({nx, ny});
        } else {
            s.pop();
        }
    }
}

bool isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && (grid[x][y] == EMPTY || grid[x][y] == END);
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);  // Manhattan distance
}

void reconstructPath(Node* endNode) {
    Node* current = endNode->parent;
    while (current && grid[current->x][current->y] != START) {
        grid[current->x][current->y] = PATH;
        current = current->parent;
    }
}

void drawGrid(RenderWindow& window) {
    RectangleShape cell(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (grid[i][j]) {
                case EMPTY:   cell.setFillColor(Color::White); break;
                case WALL:    cell.setFillColor(Color::Black); break;
                case START:   cell.setFillColor(Color::Green); break;
                case END:     cell.setFillColor(Color::Red); break;
                case PATH:    cell.setFillColor(Color::Blue); break;
                case VISITED: cell.setFillColor(Color(173, 216, 231)); break;
            }
            cell.setPosition(Vector2f(static_cast<float>(j * CELL_SIZE), static_cast<float>(i * CELL_SIZE)));
            window.draw(cell);
        }
    }
    window.display();
}

void AStarStepByStep(RenderWindow& window, int startX, int startY, int endX, int endY) {
    priority_queue<Node*, vector<Node*>, Compare> openSet;
    vector<vector<bool>> closedSet(ROWS, vector<bool>(COLS, false));

    openSet.push(new Node(startX, startY, 0, heuristic(startX, startY, endX, endY)));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        int x = current->x, y = current->y;
        if (closedSet[x][y])
            continue;
        closedSet[x][y] = true;

        if (grid[x][y] != START && grid[x][y] != END)
            grid[x][y] = VISITED;

        if (x == endX && y == endY) {
            reconstructPath(current);
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (isValid(nx, ny) && !closedSet[nx][ny]) {
                int g = current->g + 1;
                int h = heuristic(nx, ny, endX, endY);
                openSet.push(new Node(nx, ny, g, h, current));
            }
        }

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        drawGrid(window);
        this_thread::sleep_for(chrono::milliseconds(15));
    }
}

int main() {
    RenderWindow window(VideoMode({WIDTH, HEIGHT}), "A* Maze Solver with Random Maze");

    // Step 1: Generate maze
    generateMaze(1, 1);

    // Step 2: Place START and END
    int startX = 1, startY = 1;
    int endX = ROWS - 2, endY = COLS - 2;
    grid[startX][startY] = START;
    grid[endX][endY] = END;

    // Step 3: Run A* Algorithm
    AStarStepByStep(window, startX, startY, endX, endY);

    // Step 4: Final display loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        drawGrid(window);
    }

    return 0;
}
