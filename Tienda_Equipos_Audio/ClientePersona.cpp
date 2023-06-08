#include "ClientePersona.h"

ClientePersona::ClientePersona():
    Cliente(),
    _correo(""),
    _nacionalidad("")
{
    this->_tipo = 'P';
}

ClientePersona::ClientePersona(std::string nombre, std::string cedula, std::string pais, std::string ciudad, std::string correo, std::string nacionalidad):
    Cliente(nombre, cedula, pais, ciudad),
	_correo(correo),
	_nacionalidad(nacionalidad)
{
    this->_tipo = 'P';
}

ClientePersona::ClientePersona(const ClientePersona& persona) :
    Cliente(persona),
    _correo(persona._correo),
    _nacionalidad(persona._nacionalidad)
{
    this->_tipo = 'P';
}

void ClientePersona::Update()
{
    // abre el archivo de texto (LO ABRE, PERO NO BORRA LO QUE YA ESTABA ESCRITO)
    std::ofstream archivo("../Archivos/notificaciones.txt", std::ios::app);
    // escribe en el archivo de texto
    archivo << "Cliente persona: " << _nombre << " ha sido notificado." << std::endl;
}

std::string ClientePersona::getCorreo() const
{
    return _correo;
}

std::string ClientePersona::getNacionalidad() const
{
    return _nacionalidad;
}

void ClientePersona::setCorreo(std::string correo)
{
    _correo = correo;
}

void ClientePersona::setNacionalidad(std::string nacionalidad)
{
	_nacionalidad = nacionalidad;
}

Cliente* ClientePersona::clonar() const
{
    return new ClientePersona(*this);
}

std::string ClientePersona::toString() const
{
    std::stringstream ss;
    ss << "---PERSONA---" << std::endl;
    ss << "Nombre: " << _nombre << std::endl;
    ss << "Cedula: " << _cedula << std::endl;
    ss << "Pais: " << _pais << std::endl;
    ss << "Ciudad: " << _ciudad << std::endl;
    ss << "Correo: " << _correo << std::endl;
    ss << "Nacionalidad: " << _nacionalidad << std::endl;
    ss << "--------------" << std::endl;
    return ss.str();
}

ClientePersona& ClientePersona::operator=(const ClientePersona& other)
{
    if (this != &other)
    {
		Cliente::operator=(other);
		_correo = other._correo;
		_nacionalidad = other._nacionalidad;
	}
    return *this;
}

bool ClientePersona::operator==(const ClientePersona& other) const
{
    return Cliente::operator==(other) && _nacionalidad == other._nacionalidad;  // solo interesa que compartan nacionalidad y cedula
}
