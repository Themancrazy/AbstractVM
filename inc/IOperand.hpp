#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include "MainHeader.hpp"

enum eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

class IOperand {
public:
	virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
	virtual eOperandType getType( void ) const = 0; // Type of the instance
	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
	virtual std::string const & toString( void ) const = 0; // String representation of the instance
	virtual ~IOperand( void ) {}
};

class Factory {
	public: 
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};

class AOperand : public IOperand {
	public:
		static Factory							factory;
		virtual IOperand const                  *operator+( IOperand const & rhs ) const;
		virtual IOperand const                  *operator-( IOperand const & rhs ) const;
		virtual IOperand const                  *operator*( IOperand const & rhs ) const;
		virtual IOperand const                  *operator/( IOperand const & rhs ) const;
		virtual IOperand const                  *operator%( IOperand const & rhs ) const;
		virtual std::string const               &toString( void ) const = 0;
};

class Int8 : public AOperand {
	public:
		Int8(char value);
		Int8(Int8 const &r);
		~Int8(void);
		const Int8          					&operator=(Int8 const &r);
		virtual std::string const               &toString( void ) const;
		virtual int                             getPrecision( void ) const;
		virtual eOperandType                    getType( void ) const;
	private:
		char                					_value;
		std::string								_valToStr;
		Int8(void);
	
};

class Int16 : public AOperand {
	public:
		Int16(short value);
		Int16(Int16 const &r);
		~Int16(void);
		const Int16          					&operator=(Int16 const &r);
		virtual std::string const               &toString( void ) const;
		virtual int                             getPrecision( void ) const;
		virtual eOperandType                    getType( void ) const;
	private:
		short                					_value;
		std::string								_valToStr;
		Int16(void);
	
};

class Int32 : public AOperand {
	public:
		Int32(int value);
		Int32(Int32 const &r);
		~Int32(void);
		const Int32          					&operator=(Int32 const &r);
		virtual std::string const               &toString( void ) const;
		virtual int                             getPrecision( void ) const;
		virtual eOperandType                    getType( void ) const;
	private:
		int      	          					_value;
		std::string								_valToStr;
		Int32(void);
	
};

class Float : public AOperand {
	public:
		Float(float value);
		Float(Float const &r);
		~Float(void);
		const Float          					&operator=(Float const &r);
		virtual std::string const               &toString( void ) const;
		virtual int                             getPrecision( void ) const;
		virtual eOperandType                    getType( void ) const;
	private:
		float                					_value;
		std::string								_valToStr;
		Float(void);
	
};

class Double : public AOperand {
	public:
		Double(double value);
		Double(Double const &r);
		~Double(void);
		const Double          					&operator=(Double const &r);
		virtual std::string const               &toString( void ) const;
		virtual int                             getPrecision( void ) const;
		virtual eOperandType                    getType( void ) const;
	private:
		double                					_value;
		std::string								_valToStr;
		Double(void);
	
};
#endif