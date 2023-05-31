#pragma once
#include <stdexcept>
class ComponenteNoEncontradoException :
	public std::exception
{
public:
    ComponenteNoEncontradoException(const std::string& mensaje);
    const char* what() const noexcept override;
private:
    std::string _mensaje;
};

