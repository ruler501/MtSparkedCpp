#ifndef _MTSPARKED_FILEPROVIDER_H_
#define _MTSPARKED_FILEPROVIDER_H_

#include <future>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <vector>

#include "compiletimeplugins/utils.h"

#include "mtsparked/utils/erasedcontainer.h"

struct File;

template <typename Buffer>
class FileProviderFeature {
protected:


public:
    std::future<File> saveFileUserPrompt(const ErasedContainer<std::byte>::type<>& dataToSave, const std::optional<std::string>& suggestedFileName=std::nullopt) {

    }

    bool saveFile(const ErasedContainer<std::byte>::type<>& fileContents, const std::string& path) {

    }

    std::future<File> openFileUserPrompt(const std::optional<std::string>& suggestedFileName=std::nullopt) {

    }

    std::future<File> openFile(const std::string& path) {

    }

    bool doesPathExist(const std::string& path) {

    }

    bool isPathFile(const std::string& path) {

    }

    bool isPathDirectory(const std::string& path) {

    }

    std::future<bool> shareFile(const std::string& path, const std::string& mimeType="text/*") {

    }

    void releaseFile(const std::string& path) {

    }
};

template <typename... Features>
using FileProvider = erased<FileProviderFeature, Features...>;

struct File {
private:
    std::weak_ptr<FileProvider<>> provider{};

public:
    std::string name;
    std::string path;
    std::vector<std::byte> contents;

    explicit File(std::string _name) : name(std::move(_name)) { }

    File(const std::string& _name, std::weak_ptr<FileProvider<>> _provider)
            : File(_name), provider(_provider)
    { }

    File(const std::string& _name, const ErasedContainer<std::byte>::type& _contents)
            : File(_name), contents(_contents.begin(), _contents.end())
    { }

    File(const std::string& _name, const ErasedContainer<std::byte>::type& _contents, std::weak_ptr<FileProvider<>> _provider)
            : File(_name, _contents), provider(_provider)
    { }

    File(const std::string& _name, std::string _path, const ErasedContainer<std::byte>::type& _contents)
            : File(_name, _contents), path(std::move(_path))
    { }

    File(const std::string& _name, const std::string& _path, const ErasedContainer<std::byte>::type& _contents,
         std::weak_ptr<FileProvider<>> _provider)
            : File(_name, _path, _contents), provider(_provider)
    { }

    ~File() {
        this->release();zzzzzzzzzzzzzzzzzzzzzzzz
    }

    bool save() {
        std::shared_ptr<FileProvider<>> providerPtr{provider};
        return providerPtr->saveFile(ErasedContainer{type_value<std::vector<std::byte>>{}, this->contents}, this->path);
    }

    void release() {
        if(!provider.expired()) {
            std::shared_ptr<FileProvider<>> providerPtr{provider};
            providerPtr->releaseFile(this->path);
            this->provider = {};
        }
    }
};

#endif // !_MTSPAREKD_FILEPROVIDER_H_
