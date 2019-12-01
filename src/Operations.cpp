#include "MainHeader.hpp"

/*------------------FACTORY_MEMBER_IMPLEMENTATION-------------------*/
IOperand const *Factory::createOperand( eOperandType type, std::string const & value ) const {
	if (type == Int8)
		return (createInt8(value));
	else if (type == Int16)
		return (createInt16(value));
	else if (type == Int32)
		return (createInt32(value));
	else if (type == Float)
		return (createFloat(value));
	else if (type == Double)
		return (createDouble(value));
	return (nullptr);
}

IOperand const *Factory::createInt8( std::string const & value ) const {
	int		number;

	if (!isNumber(value))
    	throw SyntaxError();
	number = std::stoi(value);
	if (number > std::numeric_limits<char>::max())
		throw OverflowError();
	else if (number < std::numeric_limits<char>::min())
		throw UnderflowError();
	return (new class Int8(static_cast<char>(number)));
}

IOperand const *Factory::createInt16( std::string const & value ) const {
	int		number;

	if (!isNumber(value))
    	throw SyntaxError();
	number = std::stoi(value);
	if (number > std::numeric_limits<short>::max())
		throw OverflowError();
	else if (number < std::numeric_limits<short>::min())
		throw UnderflowError();
	return (new class Int16(static_cast<short>(number)));
}

IOperand const *Factory::createInt32( std::string const & value ) const {
	int		number;

	if (!isNumber(value))
    	throw SyntaxError();
	number = std::stoi(value);
	if (number > std::numeric_limits<int>::max())
		throw OverflowError();
	else if (number < std::numeric_limits<int>::min())
		throw UnderflowError();
	return (new class Int32(number));
}

IOperand const *Factory::createFloat( std::string const & value ) const {
	float		number;

	if (!isNumber(value))
    	throw SyntaxError();
	number = std::stof(value);
	if (number > std::numeric_limits<float>::max())
		throw OverflowError();
	else if (number < std::numeric_limits<float>::min())
		throw UnderflowError();
	return (new class Float(number));
}

IOperand const *Factory::createDouble( std::string const & value ) const {
	double		number;

	if (!isNumber(value))
    	throw SyntaxError();
	number = std::stod(value);
	if (number > std::numeric_limits<double>::max())
		throw OverflowError();
	else if (number < std::numeric_limits<double>::min())
		throw UnderflowError();
	return (new class Double(number));
}

/*------------------OVERLOAD_IMPLEMENTATION-------------------*/

Factory                 AOperand::factory;

IOperand const			*AOperand::operator+(IOperand const &value) const {
	eOperandType type;
	std::ostringstream newValue;

	type = std::max(this->getType(), value.getType());
	newValue << (std::stod(this->toString()) + (std::stod(value.toString())));
	return (this->factory.createOperand(type, newValue.str()));
}

IOperand const			*AOperand::operator-(IOperand const &value) const {
	eOperandType type;
	std::ostringstream newValue;

	type = std::max(this->getType(), value.getType());
	newValue << (std::stod(this->toString()) - (std::stod(value.toString())));
	return (this->factory.createOperand(type, newValue.str()));
}

IOperand const			*AOperand::operator*(IOperand const &value) const {
	eOperandType type;
	std::ostringstream newValue;

	type = std::max(this->getType(), value.getType());
	newValue << (std::stod(this->toString()) * (std::stod(value.toString())));
	return (this->factory.createOperand(type, newValue.str()));
}

IOperand const			*AOperand::operator/(IOperand const &value) const {
	eOperandType type;
	std::ostringstream newValue;

	type = std::max(this->getType(), value.getType());
	if (std::stoi(value.toString()) == 0)
		throw DivisionByZero();
	newValue << (std::stod(this->toString()) / (std::stod(value.toString())));
	return (this->factory.createOperand(type, newValue.str()));
}

IOperand const			*AOperand::operator%(IOperand const &value) const {
	eOperandType type;
	std::ostringstream newValue;

	type = std::max(this->getType(), value.getType());
	if (std::stoi(value.toString()) == 0)
		throw DivisionByZero();
	newValue << (std::stoi(this->toString()) % (std::stoi(value.toString())));
	return (this->factory.createOperand(type, newValue.str()));
}

/*------------------OPERAND_CLASS_IMPLEMENTATION-------------------*/

/*-----------------------------------------------------------------*/
/*--------------------INT8_CLASS_IMPLEMENTATION--------------------*/
/*-----------------------------------------------------------------*/

Int8::Int8(void) : _value(0), _valToStr("") {return ;}
Int8::Int8(char value) : _value(value) {
	std::ostringstream convert;   // stream used for the conversion
	convert << static_cast<int>(value);
	this->_valToStr = convert.str();
	return ;
}
Int8::~Int8(void) {return ;}
std::string const               &Int8::toString(void) const { return this->_valToStr; }
int                             Int8::getPrecision(void) const { return 0; }
eOperandType                    Int8::getType(void) const { return eOperandType::Int8; }

/*-----------------------------------------------------------------*/
/*--------------------INT16_CLASS_IMPLEMENTATION--------------------*/
/*-----------------------------------------------------------------*/

Int16::Int16(void) : _value(0), _valToStr("") {return ;}
Int16::Int16(short value) : _value(value) {
	std::ostringstream convert;   // stream used for the conversion
	convert << value;
	this->_valToStr = convert.str();
	return ;
}
Int16::~Int16(void) {return ;}
std::string const               &Int16::toString(void) const { return this->_valToStr; }
int                             Int16::getPrecision(void) const { return 0; }
eOperandType                    Int16::getType(void) const { return eOperandType::Int16; }

/*-----------------------------------------------------------------*/
/*-------------------INT32_CLASS_IMPLEMENTATION--------------------*/
/*-----------------------------------------------------------------*/

Int32::Int32(void) : _value(0), _valToStr("") {return ;}
Int32::Int32(int value) : _value(value) {
	std::ostringstream convert;   // stream used for the conversion
	convert << value;
	this->_valToStr = convert.str();
	return ;
}
Int32::~Int32(void) {return ;}
std::string const               &Int32::toString(void) const { return this->_valToStr; }
int                             Int32::getPrecision(void) const { return 0; }
eOperandType                    Int32::getType(void) const { return eOperandType::Int32; }

/*-----------------------------------------------------------------*/
/*-------------------FLOAT_CLASS_IMPLEMENTATION--------------------*/
/*-----------------------------------------------------------------*/

Float::Float(void) : _value(0), _valToStr("") {return ;}
Float::Float(float value) : _value(value) {
	std::ostringstream convert;   // stream used for the conversion
	convert << value;
	this->_valToStr = convert.str();
	return ;
}
Float::~Float(void) {return ;}
std::string const               &Float::toString(void) const { return this->_valToStr; }
int                             Float::getPrecision(void) const { return 7; }
eOperandType                    Float::getType(void) const { return eOperandType::Float; }

/*-----------------------------------------------------------------*/
/*-------------------DOUBLE_CLASS_IMPLEMENTATION--------------------*/
/*-----------------------------------------------------------------*/

Double::Double(void) : _value(0), _valToStr("") {return ;}
Double::Double(double value) : _value(value) {
	std::ostringstream convert;   // stream used for the conversion
	convert << value;
	this->_valToStr = convert.str();
	return ;
}
Double::~Double(void) {return ;}
std::string const               &Double::toString(void) const { return this->_valToStr; }
int                             Double::getPrecision(void) const { return 15; }
eOperandType                    Double::getType(void) const { return eOperandType::Double; }
