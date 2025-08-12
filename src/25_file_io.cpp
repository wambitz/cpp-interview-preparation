/*
 * File I/O - Interview Topics
 * 
 * Key Topics to Cover:
 * - ifstream, ofstream, fstream usage
 * - File opening modes (in, out, app, ate, trunc, binary)
 * - Error handling and stream state checking
 * - Binary vs text file operations
 * - Stream positioning (seekg, seekp, tellg, tellp)
 * - RAII with file streams
 * - File manipulation and directory operations
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <filesystem>

// TODO: Implement these classes for file I/O demonstrations

// 1. Text file handler class with RAII
class TextFileHandler {
private:
    std::fstream file;
    std::string filename;
    
public:
    TextFileHandler(const std::string& fname);
    ~TextFileHandler();
    
    // Non-copyable
    TextFileHandler(const TextFileHandler&) = delete;
    TextFileHandler& operator=(const TextFileHandler&) = delete;
    
    // File operations
    bool openForReading();
    bool openForWriting();
    bool openForAppending();
    
    bool writeString(const std::string& data);
    bool writeLine(const std::string& line);
    std::string readString();
    std::string readLine();
    std::vector<std::string> readAllLines();
    
    bool isOpen() const;
    bool isEOF() const;
    bool hasError() const;
    void clearError();
    void close();
    
    // Stream positioning
    void seekToBeginning();
    void seekToEnd();
    std::streampos getCurrentPosition();
    bool seekTo(std::streampos pos);
};

// 2. Binary file handler
class BinaryFileHandler {
private:
    std::fstream file;
    std::string filename;
    
public:
    BinaryFileHandler(const std::string& fname);
    ~BinaryFileHandler();
    
    // Non-copyable
    BinaryFileHandler(const BinaryFileHandler&) = delete;
    BinaryFileHandler& operator=(const BinaryFileHandler&) = delete;
    
    bool openForReading();
    bool openForWriting();
    bool openForReadWrite();
    
    // Template for writing/reading any POD type
    template<typename T>
    bool write(const T& data);
    
    template<typename T>
    bool read(T& data);
    
    // Write/read arrays
    template<typename T>
    bool writeArray(const T* data, size_t count);
    
    template<typename T>
    bool readArray(T* data, size_t count);
    
    // Write/read strings
    bool writeString(const std::string& str);
    bool readString(std::string& str);
    
    // File manipulation
    std::streamsize getFileSize();
    bool isOpen() const;
    void close();
    
    // Stream positioning
    std::streampos tellRead();
    std::streampos tellWrite();
    bool seekRead(std::streampos pos);
    bool seekWrite(std::streampos pos);
};

// 3. Configuration file handler
class ConfigFileHandler {
private:
    std::string filename;
    std::map<std::string, std::string> config;
    
public:
    ConfigFileHandler(const std::string& fname);
    
    bool loadConfig();
    bool saveConfig();
    
    void setString(const std::string& key, const std::string& value);
    void setInt(const std::string& key, int value);
    void setDouble(const std::string& key, double value);
    void setBool(const std::string& key, bool value);
    
    std::string getString(const std::string& key, const std::string& defaultValue = "");
    int getInt(const std::string& key, int defaultValue = 0);
    double getDouble(const std::string& key, double defaultValue = 0.0);
    bool getBool(const std::string& key, bool defaultValue = false);
    
    bool hasKey(const std::string& key) const;
    void removeKey(const std::string& key);
    void clear();
    
    void printAll() const;
};

// 4. CSV file handler
class CSVFileHandler {
private:
    std::string filename;
    char delimiter;
    
public:
    CSVFileHandler(const std::string& fname, char delim = ',');
    
    // Reading CSV
    std::vector<std::vector<std::string>> readAll();
    std::vector<std::string> readRow(std::ifstream& file);
    
    // Writing CSV
    bool writeAll(const std::vector<std::vector<std::string>>& data);
    bool writeRow(std::ofstream& file, const std::vector<std::string>& row);
    bool appendRow(const std::vector<std::string>& row);
    
    // CSV utilities
    std::string escapeField(const std::string& field);
    std::vector<std::string> parseRow(const std::string& line);
};

// 5. Log file handler
class LogFileHandler {
public:
    enum LogLevel { DEBUG, INFO, WARNING, ERROR };
    
private:
    std::ofstream logFile;
    std::string filename;
    LogLevel currentLevel;
    
public:
    LogFileHandler(const std::string& fname, LogLevel level = INFO);
    ~LogFileHandler();
    
    void setLogLevel(LogLevel level);
    
    void log(LogLevel level, const std::string& message);
    void debug(const std::string& message);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
    
    bool isOpen() const;
    void flush();
    
private:
    std::string getCurrentTimestamp();
    std::string levelToString(LogLevel level);
    bool shouldLog(LogLevel level) const;
};

// Function prototypes for demonstrations
void demonstrateBasicFileIO();
void demonstrateFileOpeningModes();
void demonstrateErrorHandling();
void demonstrateBinaryFileOperations();
void demonstrateStreamPositioning();
void demonstrateRAIIFileHandling();
void demonstrateConfigurationFiles();
void demonstrateCSVProcessing();
void demonstrateLogFileHandling();
void demonstrateFileSystemOperations();

int main() {
    std::cout << "=== File I/O Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicFileIO();
    demonstrateFileOpeningModes();
    demonstrateErrorHandling();
    demonstrateBinaryFileOperations();
    demonstrateStreamPositioning();
    demonstrateRAIIFileHandling();
    demonstrateConfigurationFiles();
    demonstrateCSVProcessing();
    demonstrateLogFileHandling();
    demonstrateFileSystemOperations();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicFileIO() {
    std::cout << "1. Basic File I/O Operations:\n";
    
    // Writing to a file
    std::ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File I/O!\n";
        outFile << "This is line 2\n";
        outFile << "Number: " << 42 << "\n";
        outFile.close();
        std::cout << "File written successfully\n";
    } else {
        std::cout << "Failed to open file for writing\n";
    }
    
    // Reading from a file
    std::ifstream inFile("example.txt");
    if (inFile.is_open()) {
        std::string line;
        std::cout << "File contents:\n";
        while (std::getline(inFile, line)) {
            std::cout << "  " << line << "\n";
        }
        inFile.close();
    } else {
        std::cout << "Failed to open file for reading\n";
    }
    
    // Read entire file into string
    std::ifstream file("example.txt");
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();
        std::cout << "Entire file content:\n" << content << "\n";
        file.close();
    }
    
    // TODO: Show different reading methods
    // Character by character reading
    // Word by word reading
    // Line by line reading
    // Binary reading
    
    std::cout << "---\n\n";
}

void demonstrateFileOpeningModes() {
    std::cout << "2. File Opening Modes:\n";
    
    // Different opening modes
    std::cout << "std::ios::in - Input (read)\n";
    std::cout << "std::ios::out - Output (write)\n";
    std::cout << "std::ios::app - Append\n";
    std::cout << "std::ios::ate - At end\n";
    std::cout << "std::ios::trunc - Truncate\n";
    std::cout << "std::ios::binary - Binary mode\n\n";
    
    // Append mode example
    std::ofstream appendFile("append_example.txt", std::ios::app);
    if (appendFile.is_open()) {
        appendFile << "Appended line 1\n";
        appendFile << "Appended line 2\n";
        appendFile.close();
        std::cout << "Data appended to file\n";
    }
    
    // Read-write mode
    std::fstream rwFile("readwrite.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if (rwFile.is_open()) {
        rwFile << "Initial content\n";
        rwFile.seekg(0);  // Go to beginning for reading
        
        std::string line;
        std::getline(rwFile, line);
        std::cout << "Read from read-write file: " << line << "\n";
        
        rwFile.close();
    }
    
    // Binary mode
    std::ofstream binaryFile("binary_example.bin", std::ios::binary);
    if (binaryFile.is_open()) {
        int numbers[] = {1, 2, 3, 4, 5};
        binaryFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
        binaryFile.close();
        std::cout << "Binary data written\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateErrorHandling() {
    std::cout << "3. Error Handling in File Operations:\n";
    
    // Try to open non-existent file
    std::ifstream file("nonexistent.txt");
    
    // Check various error states
    std::cout << "File state checks:\n";
    std::cout << "is_open(): " << (file.is_open() ? "true" : "false") << "\n";
    std::cout << "good(): " << (file.good() ? "true" : "false") << "\n";
    std::cout << "eof(): " << (file.eof() ? "true" : "false") << "\n";
    std::cout << "fail(): " << (file.fail() ? "true" : "false") << "\n";
    std::cout << "bad(): " << (file.bad() ? "true" : "false") << "\n";
    
    // Proper error checking pattern
    std::ofstream outFile("test_error.txt");
    if (!outFile) {
        std::cout << "Failed to open file for writing\n";
    } else {
        outFile << "Test content\n";
        if (outFile.fail()) {
            std::cout << "Write operation failed\n";
        } else {
            std::cout << "Write operation successful\n";
        }
        outFile.close();
    }
    
    // Exception handling with files
    try {
        std::ifstream exceptionFile;
        exceptionFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        exceptionFile.open("nonexistent_exception.txt");
        
    } catch (const std::ios_base::failure& e) {
        std::cout << "File operation exception: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateBinaryFileOperations() {
    std::cout << "4. Binary File Operations:\n";
    
    BinaryFileHandler binaryHandler("binary_demo.bin");
    
    if (binaryHandler.openForWriting()) {
        // Write different data types
        int intValue = 42;
        double doubleValue = 3.14159;
        char charArray[] = "Hello Binary";
        
        binaryHandler.write(intValue);
        binaryHandler.write(doubleValue);
        binaryHandler.writeArray(charArray, sizeof(charArray));
        
        std::string str = "Binary String";
        binaryHandler.writeString(str);
        
        std::cout << "Binary data written\n";
        binaryHandler.close();
    }
    
    if (binaryHandler.openForReading()) {
        // Read the data back
        int readInt;
        double readDouble;
        char readCharArray[20];
        std::string readString;
        
        binaryHandler.read(readInt);
        binaryHandler.read(readDouble);
        binaryHandler.readArray(readCharArray, sizeof(readCharArray));
        binaryHandler.readString(readString);
        
        std::cout << "Read binary data:\n";
        std::cout << "  Int: " << readInt << "\n";
        std::cout << "  Double: " << readDouble << "\n";
        std::cout << "  Char array: " << readCharArray << "\n";
        std::cout << "  String: " << readString << "\n";
        
        binaryHandler.close();
    }
    
    std::cout << "---\n\n";
}

void demonstrateStreamPositioning() {
    std::cout << "5. Stream Positioning:\n";
    
    // Create a file with numbered lines
    std::ofstream outFile("positioning_demo.txt");
    for (int i = 1; i <= 10; ++i) {
        outFile << "Line " << i << "\n";
    }
    outFile.close();
    
    // Demonstrate positioning
    std::ifstream inFile("positioning_demo.txt");
    if (inFile.is_open()) {
        // Get current position
        std::streampos pos = inFile.tellg();
        std::cout << "Initial position: " << pos << "\n";
        
        // Read first line
        std::string line;
        std::getline(inFile, line);
        std::cout << "First line: " << line << "\n";
        std::cout << "Position after first line: " << inFile.tellg() << "\n";
        
        // Seek to specific position
        inFile.seekg(0, std::ios::end);  // Go to end
        std::streampos fileSize = inFile.tellg();
        std::cout << "File size: " << fileSize << " bytes\n";
        
        // Go back to beginning
        inFile.seekg(0, std::ios::beg);
        
        // Skip to middle of file
        inFile.seekg(fileSize / 2);
        std::getline(inFile, line);
        std::cout << "Line from middle: " << line << "\n";
        
        inFile.close();
    }
    
    // Demonstrate bidirectional positioning with fstream
    std::fstream rwFile("positioning_demo.txt", std::ios::in | std::ios::out);
    if (rwFile.is_open()) {
        // Read position and write position can be different
        std::cout << "Read position: " << rwFile.tellg() << "\n";
        std::cout << "Write position: " << rwFile.tellp() << "\n";
        
        // Seek write position to end for appending
        rwFile.seekp(0, std::ios::end);
        rwFile << "Appended line\n";
        
        std::cout << "After append - Read pos: " << rwFile.tellg() 
                  << ", Write pos: " << rwFile.tellp() << "\n";
        
        rwFile.close();
    }
    
    std::cout << "---\n\n";
}

void demonstrateRAIIFileHandling() {
    std::cout << "6. RAII File Handling:\n";
    
    // Using TextFileHandler class
    {
        TextFileHandler handler("raii_demo.txt");
        
        if (handler.openForWriting()) {
            handler.writeLine("RAII managed file");
            handler.writeLine("Automatic cleanup");
            handler.writeLine("Exception safe");
            std::cout << "Data written using RAII handler\n";
        }
        // File automatically closed when handler goes out of scope
    }
    
    // Read it back
    {
        TextFileHandler reader("raii_demo.txt");
        if (reader.openForReading()) {
            auto lines = reader.readAllLines();
            std::cout << "Read lines using RAII:\n";
            for (const auto& line : lines) {
                std::cout << "  " << line << "\n";
            }
        }
        // File automatically closed
    }
    
    // Show exception safety
    try {
        TextFileHandler handler("raii_exception.txt");
        handler.openForWriting();
        handler.writeLine("Before exception");
        
        // Simulate exception
        throw std::runtime_error("Simulated error");
        
        handler.writeLine("This won't be written");
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
        std::cout << "File still properly closed due to RAII\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateConfigurationFiles() {
    std::cout << "7. Configuration File Handling:\n";
    
    ConfigFileHandler config("app_config.txt");
    
    // Set various configuration values
    config.setString("app_name", "MyApplication");
    config.setInt("window_width", 1024);
    config.setInt("window_height", 768);
    config.setDouble("volume", 0.75);
    config.setBool("fullscreen", false);
    config.setString("language", "en_US");
    
    // Save configuration
    if (config.saveConfig()) {
        std::cout << "Configuration saved\n";
    }
    
    // Load and read configuration
    ConfigFileHandler loadedConfig("app_config.txt");
    if (loadedConfig.loadConfig()) {
        std::cout << "Configuration loaded:\n";
        loadedConfig.printAll();
        
        // Get specific values
        std::string appName = loadedConfig.getString("app_name");
        int width = loadedConfig.getInt("window_width");
        double volume = loadedConfig.getDouble("volume");
        bool fullscreen = loadedConfig.getBool("fullscreen");
        
        std::cout << "\nParsed values:\n";
        std::cout << "App Name: " << appName << "\n";
        std::cout << "Window: " << width << "x" << loadedConfig.getInt("window_height") << "\n";
        std::cout << "Volume: " << volume << "\n";
        std::cout << "Fullscreen: " << (fullscreen ? "Yes" : "No") << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateCSVProcessing() {
    std::cout << "8. CSV File Processing:\n";
    
    CSVFileHandler csv("employees.csv");
    
    // Create sample CSV data
    std::vector<std::vector<std::string>> employeeData = {
        {"Name", "Age", "Department", "Salary"},
        {"John Doe", "30", "Engineering", "75000"},
        {"Jane Smith", "28", "Marketing", "65000"},
        {"Bob Johnson", "35", "Engineering", "85000"},
        {"Alice Brown", "32", "HR", "60000"}
    };
    
    // Write CSV file
    if (csv.writeAll(employeeData)) {
        std::cout << "CSV file written successfully\n";
    }
    
    // Read CSV file
    auto readData = csv.readAll();
    std::cout << "CSV file contents:\n";
    for (const auto& row : readData) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << " | ";
        }
        std::cout << "\n";
    }
    
    // Append new row
    csv.appendRow({"Charlie Wilson", "29", "Sales", "55000"});
    std::cout << "New row appended\n";
    
    std::cout << "---\n\n";
}

void demonstrateLogFileHandling() {
    std::cout << "9. Log File Handling:\n";
    
    LogFileHandler logger("application.log", LogFileHandler::DEBUG);
    
    // Log different types of messages
    logger.debug("Application starting up");
    logger.info("Configuration loaded successfully");
    logger.warning("Low disk space detected");
    logger.error("Failed to connect to database");
    logger.info("Application shutdown complete");
    
    std::cout << "Log entries written to application.log\n";
    
    // Change log level
    logger.setLogLevel(LogFileHandler::WARNING);
    logger.debug("This debug message won't be logged");
    logger.info("This info message won't be logged");
    logger.warning("This warning will be logged");
    logger.error("This error will be logged");
    
    // Read log file to show contents
    std::ifstream logFile("application.log");
    if (logFile.is_open()) {
        std::cout << "\nLog file contents:\n";
        std::string line;
        while (std::getline(logFile, line)) {
            std::cout << "  " << line << "\n";
        }
        logFile.close();
    }
    
    std::cout << "---\n\n";
}

void demonstrateFileSystemOperations() {
    std::cout << "10. File System Operations (C++17):\n";
    
    // TODO: Show modern file system operations
    // Note: These require C++17 and <filesystem>
    
    try {
        // Check if file exists
        if (std::filesystem::exists("example.txt")) {
            std::cout << "example.txt exists\n";
            
            // Get file size
            auto size = std::filesystem::file_size("example.txt");
            std::cout << "File size: " << size << " bytes\n";
            
            // Get last write time
            auto ftime = std::filesystem::last_write_time("example.txt");
            std::cout << "Last modified: " << std::filesystem::file_time_type::clock::to_time_t(ftime) << "\n";
        }
        
        // Create directory
        std::filesystem::create_directory("test_dir");
        std::cout << "Directory created\n";
        
        // List directory contents
        std::cout << "Current directory contents:\n";
        for (const auto& entry : std::filesystem::directory_iterator(".")) {
            if (entry.is_regular_file()) {
                std::cout << "  File: " << entry.path().filename() << "\n";
            } else if (entry.is_directory()) {
                std::cout << "  Dir:  " << entry.path().filename() << "\n";
            }
        }
        
        // Copy file
        if (std::filesystem::exists("example.txt")) {
            std::filesystem::copy_file("example.txt", "example_copy.txt");
            std::cout << "File copied\n";
        }
        
    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "Filesystem error: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

// TODO: Implement all class methods

// TextFileHandler implementation
TextFileHandler::TextFileHandler(const std::string& fname) : filename(fname) {}

TextFileHandler::~TextFileHandler() {
    if (file.is_open()) {
        file.close();
    }
}

bool TextFileHandler::openForReading() {
    file.open(filename, std::ios::in);
    return file.is_open();
}

bool TextFileHandler::openForWriting() {
    file.open(filename, std::ios::out | std::ios::trunc);
    return file.is_open();
}

bool TextFileHandler::openForAppending() {
    file.open(filename, std::ios::out | std::ios::app);
    return file.is_open();
}

bool TextFileHandler::writeString(const std::string& data) {
    if (file.is_open()) {
        file << data;
        return !file.fail();
    }
    return false;
}

bool TextFileHandler::writeLine(const std::string& line) {
    return writeString(line + "\n");
}

std::string TextFileHandler::readString() {
    std::string result;
    if (file.is_open()) {
        file >> result;
    }
    return result;
}

std::string TextFileHandler::readLine() {
    std::string line;
    if (file.is_open()) {
        std::getline(file, line);
    }
    return line;
}

std::vector<std::string> TextFileHandler::readAllLines() {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

bool TextFileHandler::isOpen() const {
    return file.is_open();
}

bool TextFileHandler::isEOF() const {
    return file.eof();
}

bool TextFileHandler::hasError() const {
    return file.fail();
}

void TextFileHandler::clearError() {
    file.clear();
}

void TextFileHandler::close() {
    if (file.is_open()) {
        file.close();
    }
}

void TextFileHandler::seekToBeginning() {
    file.seekg(0, std::ios::beg);
}

void TextFileHandler::seekToEnd() {
    file.seekg(0, std::ios::end);
}

std::streampos TextFileHandler::getCurrentPosition() {
    return file.tellg();
}

bool TextFileHandler::seekTo(std::streampos pos) {
    file.seekg(pos);
    return !file.fail();
}

// TODO: Implement remaining class methods for BinaryFileHandler, ConfigFileHandler, etc.
