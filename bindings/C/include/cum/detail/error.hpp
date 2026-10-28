#ifndef CUM_C_ERROR_HPP
#define CUM_C_ERROR_HPP

#include <exception>
#include <new>
#include <stdexcept>
#include <string>

#include "cum/core.h"

namespace cum_c
{
    inline thread_local std::string last_error;

    inline cum_status_t failure(cum_status_t status, const char* message)
    {
        last_error = message;
        return status;
    }

    inline cum_status_t invalid_argument(const char* message = "invalid argument")
    {
        return failure(CUM_STATUS_INVALID_ARGUMENT, message);
    }

    /* Runs `function`, converting any exception into a status code. */
    template<typename Function>
    cum_status_t guard(Function&& function) noexcept
    {
        try
        {
            function();
            last_error.clear();
            return CUM_STATUS_SUCCESS;
        }
        catch(const std::bad_alloc& error)
        {
            return failure(CUM_STATUS_OUT_OF_MEMORY, error.what());
        }
        catch(const std::invalid_argument& error)
        {
            return failure(CUM_STATUS_INVALID_ARGUMENT, error.what());
        }
        catch(const std::exception& error)
        {
            return failure(CUM_STATUS_RUNTIME_ERROR, error.what());
        }
        catch(...)
        {
            return failure(CUM_STATUS_RUNTIME_ERROR, "unknown error");
        }
    }
}

#endif /* CUM_C_ERROR_HPP */
