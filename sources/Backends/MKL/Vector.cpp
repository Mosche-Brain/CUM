#include "cum/Vector.hpp"
#include "cum/Matrix.hpp"

#include "cum/LinearAlgebra.hpp"
#include "cum/functions/various.hpp"
#include "cum/memory.hpp"
#include "../../../include/cum/detail/vendor/oneapi/context.hpp"

namespace cum
{
	Vector::Vector(const dim_t lenght)
	{
		data_ = memory::allocate(lenght_);
	}

    Vector::Vector(std::size_t lenght, cumeric_t value) : lenght_(lenght)
    {
        data_ = sycl::malloc_shared<cumeric_t>(lenght, internal::getQueue());
    	functions::various::fill(data_, value, lenght);
	}

    Vector::operator Matrix () const
    {
        //Matrix temp(lenght_, 1);
        //for(size_t i = 0 ; i < lenght_ ; i++)
        //    temp.at(i, 0) = data_[i];
        Matrix temp(1, lenght_, data_);

		//temp.data_ = memory::allocate(lenght_);
		//temp.rows_ = 1;
		//temp.cols_ = lenght_;

		//memory::memcopy(temp.data_(), this->data_, lenght_ * sizeof(cumeric_t));

		return temp;
    }

    Vector& Vector::operator += (const Vector& other)
    {
        lara::addInPlace(this->data_, other.data_, lenght_);
        return *this;
    }

    Vector& Vector::operator += (Matrix& matrix)
    {
        lara::addInPlace(this->data_, matrix.data(), lenght_);
        return *this;
    }

    Vector& Vector::operator -=(const Vector& other)
    {
        lara::subInPlace(this->data_, other.data_, lenght_);
        return *this;
    }

    Vector& Vector::operator *= (const Vector& other)
    {
        lara::cwiseProductInPlace(this->data_, other.data_, lenght_);
        return *this;                                                                                                                      
    }

    Vector& Vector::operator *= (const cumeric_t& scalar)
    {
        lara::scaleInPlace(this->data_, scalar, lenght_);
        return *this;                                                                                                                      
    }

    Vector& Vector::operator /= (const Vector& other)
    {
        lara::divInPlace (this->data_, other.data_, lenght_);
        return *this;
    }

    Vector operator + (const Vector& v, const Vector& u)
    {
        Vector result(v.lenght_);
        lara::add(result.data_, v.data_, u.data_, v.lenght_);
        return result;
    }

    Vector operator - (const Vector& v, const Vector& u)
    {
        Vector result(v.lenght_);
        lara::sub(result.data_, v.data_, u.data_, v.lenght_);
        return result;
    }

    Vector operator * (const Vector& v, const Vector& u)
    {
        Vector result(v.lenght_);
        lara::cwiseProduct(result.data_, v.data_, u.data_, v.lenght_);
        return result;
    }

    Vector operator * (const Vector& v, const cumeric_t& scalar)
    {
        Vector result(v.lenght_);
        lara::scaleInPlace(result.data_, scalar, v.lenght_);
        return result;
    }

    Vector operator / (const Vector& v, const Vector& u)
    {
        Vector result(v.lenght_);
        lara::div(result.data_, v.data_, u.data_, v.lenght_);
        return result;
    }

    Vector Vector::dot(const Vector& other)
    {
        Vector result(1);
        // LinearAlgebra::dot(result.data_, data_, other.data_, lenght_);
        return result;
    }

    Vector& Vector::dotInPlace(const Vector& other)
    {
        // LinearAlgebra::dot(data_, data_, other.data_, lenght_);
        return *this;
    }

    cumeric_t Vector::sum()
    {
        cumeric_t result;
        lara::sum(result, data_, lenght_);
        return result;
    }

    Vector Vector::normalize()
    {
        Vector result(lenght_);
        lara::normalize(result.data_, data_, lenght_);
        return result;
    }

    Vector& Vector::normalizeInPlace()
    {
        lara::normalizeInPlace(data_, lenght_);
        return *this;
    }

} // namespace cum
