#include "myparser.h"
#include <glibmm/convert.h> //For Glib::ConvertError

#include <iostream>

MySaxParser::MySaxParser()
  : xmlpp::SaxParser()
{
}

MySaxParser::~MySaxParser()
{
}

void MySaxParser::on_start_document()
{
  std::cout << "on_start_document()" << std::endl;
}

void MySaxParser::on_end_document()
{
  std::cout << "on_end_document()" << std::endl;
}

void MySaxParser::on_start_element(const Glib::ustring& name,
                                   const AttributeList& attributes)
{
  std::cout << "node name=" << name << std::endl;

  // Print attributes:
  for(const auto& attr_pair : attributes)
  {
    try
    {
      std::cout << "  Attribute name=" <<  attr_pair.name << std::endl;
    }
    catch(const Glib::ConvertError& ex)
    {
      std::cerr << "MySaxParser::on_start_element(): Exception caught while converting name for std::cout: " << ex.what() << std::endl;
    }

    try
    {
      std::cout << "    , value= " <<  attr_pair.value << std::endl;
    }
    catch(const Glib::ConvertError& ex)
    {
      std::cerr << "MySaxParser::on_start_element(): Exception caught while converting value for std::cout: " << ex.what() << std::endl;
    }
  }
}

void MySaxParser::on_end_element(const Glib::ustring& /* name */)
{
  std::cout << "on_end_element()" << std::endl;
}

void MySaxParser::on_characters(const Glib::ustring& text)
{
  try
  {
    std::cout << "on_characters(): " << text << std::endl;
  }
  catch(const Glib::ConvertError& ex)
  {
    std::cerr << "MySaxParser::on_characters(): Exception caught while converting text for std::cout: " << ex.what() << std::endl;
  }
}

void MySaxParser::on_comment(const Glib::ustring& text)
{
  try
  {
    std::cout << "on_comment(): " << text << std::endl;
  }
  catch(const Glib::ConvertError& ex)
  {
    std::cerr << "MySaxParser::on_comment(): Exception caught while converting text for std::cout: " << ex.what() << std::endl;
  }
}

void MySaxParser::on_warning(const Glib::ustring& text)
{
  try
  {
    std::cout << "on_warning(): " << text << std::endl;
  }
  catch(const Glib::ConvertError& ex)
  {
    std::cerr << "MySaxParser::on_warning(): Exception caught while converting text for std::cout: " << ex.what() << std::endl;
  }
}

void MySaxParser::on_error(const Glib::ustring& text)
{
  try
  {
    std::cout << "on_error(): " << text << std::endl;
  }
  catch(const Glib::ConvertError& ex)
  {
    std::cerr << "MySaxParser::on_error(): Exception caught while converting text for std::cout: " << ex.what() << std::endl;
  }
}

void MySaxParser::on_fatal_error(const Glib::ustring& text)
{
  try
  {
    std::cout << "on_fatal_error(): " << text << std::endl;
  }
  catch(const Glib::ConvertError& ex)
  {
    std::cerr << "MySaxParser::on_characters(): Exception caught while converting value for std::cout: " << ex.what() << std::endl;
  }
}