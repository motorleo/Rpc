// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace test {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_test_2eproto();
void protobuf_AssignDesc_test_2eproto();
void protobuf_ShutdownFile_test_2eproto();

class testMessage;

// ===================================================================

class testMessage : public ::google::protobuf::Message {
 public:
  testMessage();
  virtual ~testMessage();

  testMessage(const testMessage& from);

  inline testMessage& operator=(const testMessage& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const testMessage& default_instance();

  void Swap(testMessage* other);

  // implements Message ----------------------------------------------

  testMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const testMessage& from);
  void MergeFrom(const testMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string echoString = 1;
  inline bool has_echostring() const;
  inline void clear_echostring();
  static const int kEchoStringFieldNumber = 1;
  inline const ::std::string& echostring() const;
  inline void set_echostring(const ::std::string& value);
  inline void set_echostring(const char* value);
  inline void set_echostring(const char* value, size_t size);
  inline ::std::string* mutable_echostring();
  inline ::std::string* release_echostring();
  inline void set_allocated_echostring(::std::string* echostring);

  // @@protoc_insertion_point(class_scope:test.testMessage)
 private:
  inline void set_has_echostring();
  inline void clear_has_echostring();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* echostring_;
  friend void  protobuf_AddDesc_test_2eproto();
  friend void protobuf_AssignDesc_test_2eproto();
  friend void protobuf_ShutdownFile_test_2eproto();

  void InitAsDefaultInstance();
  static testMessage* default_instance_;
};
// ===================================================================

class testService_Stub;

class testService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline testService() {};
 public:
  virtual ~testService();

  typedef testService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void Echo(::google::protobuf::RpcController* controller,
                       const ::test::testMessage* request,
                       ::test::testMessage* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(testService);
};

class testService_Stub : public testService {
 public:
  testService_Stub(::google::protobuf::RpcChannel* channel);
  testService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~testService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements testService ------------------------------------------

  void Echo(::google::protobuf::RpcController* controller,
                       const ::test::testMessage* request,
                       ::test::testMessage* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(testService_Stub);
};


// ===================================================================


// ===================================================================

// testMessage

// required string echoString = 1;
inline bool testMessage::has_echostring() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void testMessage::set_has_echostring() {
  _has_bits_[0] |= 0x00000001u;
}
inline void testMessage::clear_has_echostring() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void testMessage::clear_echostring() {
  if (echostring_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    echostring_->clear();
  }
  clear_has_echostring();
}
inline const ::std::string& testMessage::echostring() const {
  // @@protoc_insertion_point(field_get:test.testMessage.echoString)
  return *echostring_;
}
inline void testMessage::set_echostring(const ::std::string& value) {
  set_has_echostring();
  if (echostring_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    echostring_ = new ::std::string;
  }
  echostring_->assign(value);
  // @@protoc_insertion_point(field_set:test.testMessage.echoString)
}
inline void testMessage::set_echostring(const char* value) {
  set_has_echostring();
  if (echostring_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    echostring_ = new ::std::string;
  }
  echostring_->assign(value);
  // @@protoc_insertion_point(field_set_char:test.testMessage.echoString)
}
inline void testMessage::set_echostring(const char* value, size_t size) {
  set_has_echostring();
  if (echostring_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    echostring_ = new ::std::string;
  }
  echostring_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:test.testMessage.echoString)
}
inline ::std::string* testMessage::mutable_echostring() {
  set_has_echostring();
  if (echostring_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    echostring_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:test.testMessage.echoString)
  return echostring_;
}
inline ::std::string* testMessage::release_echostring() {
  clear_has_echostring();
  if (echostring_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = echostring_;
    echostring_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void testMessage::set_allocated_echostring(::std::string* echostring) {
  if (echostring_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete echostring_;
  }
  if (echostring) {
    set_has_echostring();
    echostring_ = echostring;
  } else {
    clear_has_echostring();
    echostring_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:test.testMessage.echoString)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace test

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED
