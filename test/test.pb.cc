// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace test {

namespace {

const ::google::protobuf::Descriptor* testMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  testMessage_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* testService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_test_2eproto() {
  protobuf_AddDesc_test_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "test.proto");
  GOOGLE_CHECK(file != NULL);
  testMessage_descriptor_ = file->message_type(0);
  static const int testMessage_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(testMessage, echostring_),
  };
  testMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      testMessage_descriptor_,
      testMessage::default_instance_,
      testMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(testMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(testMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(testMessage));
  testService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_test_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    testMessage_descriptor_, &testMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_test_2eproto() {
  delete testMessage::default_instance_;
  delete testMessage_reflection_;
}

void protobuf_AddDesc_test_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ntest.proto\022\004test\"!\n\013testMessage\022\022\n\nech"
    "oString\030\001 \002(\t2;\n\013testService\022,\n\004Echo\022\021.t"
    "est.testMessage\032\021.test.testMessageB\003\200\001\001", 119);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "test.proto", &protobuf_RegisterTypes);
  testMessage::default_instance_ = new testMessage();
  testMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_test_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_test_2eproto {
  StaticDescriptorInitializer_test_2eproto() {
    protobuf_AddDesc_test_2eproto();
  }
} static_descriptor_initializer_test_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int testMessage::kEchoStringFieldNumber;
#endif  // !_MSC_VER

testMessage::testMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:test.testMessage)
}

void testMessage::InitAsDefaultInstance() {
}

testMessage::testMessage(const testMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:test.testMessage)
}

void testMessage::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  echostring_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

testMessage::~testMessage() {
  // @@protoc_insertion_point(destructor:test.testMessage)
  SharedDtor();
}

void testMessage::SharedDtor() {
  if (echostring_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete echostring_;
  }
  if (this != default_instance_) {
  }
}

void testMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* testMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return testMessage_descriptor_;
}

const testMessage& testMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_test_2eproto();
  return *default_instance_;
}

testMessage* testMessage::default_instance_ = NULL;

testMessage* testMessage::New() const {
  return new testMessage;
}

void testMessage::Clear() {
  if (has_echostring()) {
    if (echostring_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      echostring_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool testMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:test.testMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string echoString = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_echostring()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->echostring().data(), this->echostring().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "echostring");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:test.testMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:test.testMessage)
  return false;
#undef DO_
}

void testMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:test.testMessage)
  // required string echoString = 1;
  if (has_echostring()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->echostring().data(), this->echostring().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "echostring");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->echostring(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:test.testMessage)
}

::google::protobuf::uint8* testMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:test.testMessage)
  // required string echoString = 1;
  if (has_echostring()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->echostring().data(), this->echostring().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "echostring");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->echostring(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:test.testMessage)
  return target;
}

int testMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string echoString = 1;
    if (has_echostring()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->echostring());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void testMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const testMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const testMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void testMessage::MergeFrom(const testMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_echostring()) {
      set_echostring(from.echostring());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void testMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void testMessage::CopyFrom(const testMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool testMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void testMessage::Swap(testMessage* other) {
  if (other != this) {
    std::swap(echostring_, other->echostring_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata testMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = testMessage_descriptor_;
  metadata.reflection = testMessage_reflection_;
  return metadata;
}


// ===================================================================

testService::~testService() {}

const ::google::protobuf::ServiceDescriptor* testService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return testService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* testService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return testService_descriptor_;
}

void testService::Echo(::google::protobuf::RpcController* controller,
                         const ::test::testMessage*,
                         ::test::testMessage*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Echo() not implemented.");
  done->Run();
}

void testService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), testService_descriptor_);
  switch(method->index()) {
    case 0:
      Echo(controller,
             ::google::protobuf::down_cast<const ::test::testMessage*>(request),
             ::google::protobuf::down_cast< ::test::testMessage*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& testService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::test::testMessage::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& testService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::test::testMessage::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

testService_Stub::testService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
testService_Stub::testService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
testService_Stub::~testService_Stub() {
  if (owns_channel_) delete channel_;
}

void testService_Stub::Echo(::google::protobuf::RpcController* controller,
                              const ::test::testMessage* request,
                              ::test::testMessage* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace test

// @@protoc_insertion_point(global_scope)
