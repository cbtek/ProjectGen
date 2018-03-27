#pragma once

//std headers
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
#include <vector>

//utility headers
#include "UtilityCommon.hpp"

BEG_NAMESPACE_CBTEK_UTILITY
namespace ParseUtils
{
    const static bool c_DEFAULT_REVERSE_BYTES = false;

    ///
    /// @brief Reverses all bytes in a plain old data type
    /// @param src The plain old data type to reverse
    /// @return The reversed plain old data type
    ///
    template <typename T>
    inline T reverse(T  src)
    {
        T dest;
        char * fb = (char *)(&src);
        char * tb = (char *)(&dest);
        size_t count = sizeof(T);
        for (size_t i = 0; i < count; ++i)
        {
            tb[i]=fb[(count-1)-i];
        }
        return dest;
    }

    /**
    * @brief Templated function to read
    *        plain old data types from an input stream
    * @param[out] in Reference to input stream
    * @param reverseBytes Should bytes be reversed before
    * returning the value?
    * @return Return the requested POD type from input stream
    */
    template <typename T>
    inline T read(std::istream & in,
                  bool reverseBytes = c_DEFAULT_REVERSE_BYTES)
    {
        size_t size = sizeof(T);
        if (size==1)return (T)in.get();
        char * buffer = new char[size];
        T value;
        in.read(buffer,size);
        memcpy(&value,buffer,size);

        delete [] buffer;
        if (reverseBytes)
        {
            return reverse<T>(value);
        }
        else return value;
    }

    /**
     * @brief Read value POD type (T) from the data buffer
     * @param data The data buffer to read from
     * @param reverseBytes Should I reverse bytes in
     * the return value?
     * @return Return the requested POD type from data buffer
     */
    template <typename T>
    inline T read(const char * data,
                  size_t & offset,
                  bool reverseBytes = c_DEFAULT_REVERSE_BYTES)
    {
        T value;
        size_t byteSize=sizeof(value);
        memcpy(&value,&data[offset],byteSize);
        offset+=byteSize;
        if (reverseBytes)
        {
            return reverse<T>(value);
        }
        else return value;
    }

    /**
     * @brief Write value type (T) to output stream (out)
     * @param[out] out The output stream to write to
     * @param value The value to be written
     * @return Return true upon success, false if stream
     * is invalid.
     */
    template <typename T>
    inline bool write(std::ostream & out,
                      const T & value)
    {
        if (!out)return false;
        const char * buffer = reinterpret_cast<const char *>(&value);
        out.write(buffer,sizeof(T));
        return true;
    }

    /**
    * @brief Reads a string from the input stream
    * @param[out] in Reference to input stream
    * @param[out] stringOut Reference to string out variable
    * @param count Number of bytes to read from input stream
    * @return true if read was successful otherwise false
    */
    inline bool readString(std::istream & in,
                    std::string & stringOut,
                    size_t count)
    {

        for (size_t a1 = 0;a1<(size_t)count;++a1)
        {
            stringOut.push_back(static_cast<char>(in.get()));
        }
        return true;
    }

    /**
    * @brief Read std::string from byte buffer
    * @param data The buffer to read from
    * @param[out] offset  The offset into data
    * @param stringOut The output string
    * @param count Number of bytes to read
    * @return true if successful, false otherwise
    */
    inline bool readString(const char * data,
                    size_t & offset,
                    std::string & stringOut,
                    size_t count)
    {
        for (size_t a1 = 0;a1<(size_t)count;++a1)
        {
            stringOut.push_back(data[offset+a1]);
        }
        offset+=count;
        return true;
    }

    /**
    * @brief Read bytes from input stream
    * @param[out] in Reference to input stream
    * @param[out] bytesOut Pointer to array of characters
    * @param count Number of bytes to read from input stream
    * @return true if read was successful otherwise false
    */
    inline bool readBytes(std::istream & in,
                   char ** bytesOut,
                   size_t count)
    {
        if (count == 0) return false;
        *bytesOut = new char[count];
        in.read(*bytesOut,count);
        return true;
    }

    /**
    * @brief Read bytes from input stream
    * @param[out] in The input stream
    * @param[out] bytesOut The buffer to read into
    * @param count The number of bytes to read from in
    * @param offset The offset into in
    * @return true if successful, false if stream
    * is invalid
    */
    inline bool readBytesAt(std::istream &in,
                     char **bytesOut,
                     size_t count,
                     size_t offset)
    {
        if (count == 0) return false;
        in.seekg(offset,std::ios::beg);
        if (!in)return false;
        *bytesOut = new char[count];
        in.read(*bytesOut,count);
        return true;
    }

    inline size_t getNumPadding(size_t byte_boundary_size, size_t current_byte_pos)
    {
        if (current_byte_pos == byte_boundary_size ||
            current_byte_pos % byte_boundary_size == 0)
        {
            return 0;
        }

        else if (current_byte_pos < byte_boundary_size)
        {
            return byte_boundary_size - current_byte_pos;
        }
        else
        {
            size_t remainder = current_byte_pos % byte_boundary_size;
            return byte_boundary_size - remainder;
        }
    }

    inline char * readBytes(std::istream &in, size_t count,bool swap_bytes = false)
    {
        if (count == 0) return nullptr;
        char * buffer_out = new char[count];
        in.read(buffer_out,count);
        return buffer_out;
    }

    inline char * readBytes(const char * data_buffer, size_t count, size_t &offset,bool swap_bytes = false)
    {
        if (count == 0) return nullptr;
        char * buffer_out = new char[count];
        size_t start_offset = offset;
        for (size_t a1 = 0; a1 < count; ++a1)
        {
            buffer_out[a1] = data_buffer[start_offset+a1];
            ++offset;
        }
        return buffer_out;
    }
    template <typename T>
    inline std::vector<T> readArray(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES)
    {
        std::vector<T> values;
        for (size_t a1 = 0; a1 < count; ++a1)
        {
            values.push_back(ParseUtils::read<T>(in,swap_bytes));
        }
        return values;
    }
    inline std::string readString(std::istream &in,size_t count)
    {
        std::string str_out;
        readString(in,str_out,count);
        return str_out;
    }

    inline std::u16string readString16(std::istream &in,size_t count)
    {
        std::vector<char16_t> values = readArray<char16_t>(in,count);
        std::u16string str_out(values.begin(),values.end());
        return str_out;
    }

    inline std::u32string readString32(std::istream &in,size_t count)
    {
        std::vector<char32_t> values = readArray<char32_t>(in,count);
        std::u32string str_out(values.begin(),values.end());
        return str_out;
    }

    inline char readChar(std::istream &in, bool swap_bytes = false){return read<char>(in,swap_bytes);}
    inline char16_t readChar16(std::istream &in, bool swap_bytes = false){return read<char16_t>(in,swap_bytes);}
    inline char32_t readChar32(std::istream &in, bool swap_bytes = false){return read<char32_t>(in,swap_bytes);}
    inline std::uint8_t readUInt8(std::istream &in, bool swap_bytes = false){return read<std::uint8_t>(in,swap_bytes);}
    inline std::uint16_t readUInt16(std::istream &in, bool swap_bytes = false){return read<std::uint16_t>(in,swap_bytes);}
    inline std::uint32_t readUInt32(std::istream &in, bool swap_bytes = false){return read<std::uint32_t>(in,swap_bytes);}
    inline std::uint64_t readUInt64(std::istream &in, bool swap_bytes = false){return read<std::uint64_t>(in,swap_bytes);}
    inline std::int8_t readInt8(std::istream &in, bool swap_bytes = false){return read<std::int8_t>(in,swap_bytes);}
    inline std::int16_t readInt16(std::istream &in, bool swap_bytes = false){return read<std::int16_t>(in,swap_bytes);}
    inline std::int32_t readInt32(std::istream &in, bool swap_bytes = false){return read<std::int32_t>(in,swap_bytes);}
    inline std::int64_t readInt64(std::istream &in, bool swap_bytes = false){return read<std::int64_t>(in,swap_bytes);}
    inline double readFloat64(std::istream &in, bool swap_bytes = false){return read<double>(in,swap_bytes);}
    inline float readFloat32(std::istream &in, bool swap_bytes = false){return read<float>(in,swap_bytes);}
    inline std::uint8_t readUInt8(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::uint8_t>(data_buffer,data_offset,swap_bytes);}
    inline std::uint16_t readUInt16(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::uint16_t>(data_buffer,data_offset,swap_bytes);}
    inline std::uint32_t readUInt32(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::uint32_t>(data_buffer,data_offset,swap_bytes);}
    inline std::uint64_t readUInt64(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::uint64_t>(data_buffer,data_offset,swap_bytes);}
    inline std::int8_t readInt8(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::int8_t>(data_buffer,data_offset,swap_bytes);}
    inline std::int16_t readInt16(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::int16_t>(data_buffer,data_offset,swap_bytes);}
    inline std::int32_t readInt32(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::int32_t>(data_buffer,data_offset,swap_bytes);}
    inline std::int64_t readInt64(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<std::int64_t>(data_buffer,data_offset,swap_bytes);}
    inline double readFloat64(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<double>(data_buffer,data_offset,swap_bytes);}
    inline float readFloat32(const char * data_buffer, size_t &data_offset, bool swap_bytes = false){return read<float>(data_buffer,data_offset,swap_bytes);}
    inline std::vector<char> readCharArray(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<char>(in,count,swap_bytes);}
    inline std::vector<char16_t> readChar16Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<char16_t>(in,count,swap_bytes);}
    inline std::vector<char32_t> readChar32Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<char32_t>(in,count,swap_bytes);}
    inline std::vector<std::int8_t> readInt8Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::int8_t>(in,count,swap_bytes);}
    inline std::vector<std::uint8_t> readUInt8Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::uint8_t>(in,count,swap_bytes);}
    inline std::vector<std::int16_t> readInt16Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::int16_t>(in,count,swap_bytes);}
    inline std::vector<std::uint16_t> readUInt16Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::uint16_t>(in,count,swap_bytes);}
    inline std::vector<std::int32_t> readInt32Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::int32_t>(in,count,swap_bytes);}
    inline std::vector<std::uint32_t> readUInt32Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::uint32_t>(in,count,swap_bytes);}
    inline std::vector<std::int64_t> readInt64Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::int64_t>(in,count,swap_bytes);}
    inline std::vector<std::uint64_t> readUInt64Array(std::istream &in, size_t count, bool swap_bytes = c_DEFAULT_REVERSE_BYTES){return readArray<std::uint64_t>(in,count,swap_bytes);}


}
END_NAMESPACE_CBTEK_UTILITY
