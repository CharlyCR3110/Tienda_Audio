#pragma once
#include <stdexcept>

class SistemaDeAudioLlenoException :
	public std::exception
{
public:
    SistemaDeAudioLlenoException(const std::string& mensaje);
    const char* what() const noexcept override;
private:
    std::string _mensaje;

};

