CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude # 編譯選項，包含 C++17 標準和警告選項
# INCLUDES = -Iinclude  # 指定包含目錄為 include
TARGET = mini-router  # 最後要生成的執行檔名稱（現在是 mini-router）
SRC = src/RoutingTable.cpp src/ArpTable.cpp src/Router.cpp main.cpp	# 所有的源文件

all: $(TARGET)   # 當你輸入 make 時，會自動執行生成目標（$(TARGET)）

$(TARGET): $(SRC)  # 定義編譯規則：當 main.cpp 改變時要重新編譯
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# 編譯每個 .cpp 時，記得帶上 -Iinclude
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)