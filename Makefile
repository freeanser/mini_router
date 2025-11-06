CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = mini-router  # 最後要生成的執行檔名稱（現在是 mini-router）
SRC = main.cpp

all: $(TARGET)   # 當你輸入 make 時，會自動執行生成目標（$(TARGET)）

$(TARGET): $(SRC)  # 定義編譯規則：當 main.cpp 改變時要重新編譯
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)