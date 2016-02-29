// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: demo.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "demo.pb.h"

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

namespace demo {

namespace {

const ::google::protobuf::Descriptor* demoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  demoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* demoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  demoResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* demoService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_demo_2eproto() {
  protobuf_AddDesc_demo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "demo.proto");
  GOOGLE_CHECK(file != NULL);
  demoRequest_descriptor_ = file->message_type(0);
  static const int demoRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoRequest, request_),
  };
  demoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      demoRequest_descriptor_,
      demoRequest::default_instance_,
      demoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(demoRequest));
  demoResponse_descriptor_ = file->message_type(1);
  static const int demoResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoResponse, solved_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoResponse, response_),
  };
  demoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      demoResponse_descriptor_,
      demoResponse::default_instance_,
      demoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(demoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(demoResponse));
  demoService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_demo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    demoRequest_descriptor_, &demoRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    demoResponse_descriptor_, &demoResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_demo_2eproto() {
  delete demoRequest::default_instance_;
  delete demoRequest_reflection_;
  delete demoResponse::default_instance_;
  delete demoResponse_reflection_;
}

void protobuf_AddDesc_demo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ndemo.proto\022\004demo\"\036\n\013demoRequest\022\017\n\007req"
    "uest\030\001 \002(\t\"7\n\014demoResponse\022\025\n\006solved\030\001 \001"
    "(\010:\005false\022\020\n\010response\030\002 \001(\t2=\n\013demoServi"
    "ce\022.\n\005Solve\022\021.demo.demoRequest\032\022.demo.de"
    "moResponseB\003\200\001\001", 175);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "demo.proto", &protobuf_RegisterTypes);
  demoRequest::default_instance_ = new demoRequest();
  demoResponse::default_instance_ = new demoResponse();
  demoRequest::default_instance_->InitAsDefaultInstance();
  demoResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_demo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_demo_2eproto {
  StaticDescriptorInitializer_demo_2eproto() {
    protobuf_AddDesc_demo_2eproto();
  }
} static_descriptor_initializer_demo_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int demoRequest::kRequestFieldNumber;
#endif  // !_MSC_VER

demoRequest::demoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:demo.demoRequest)
}

void demoRequest::InitAsDefaultInstance() {
}

demoRequest::demoRequest(const demoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:demo.demoRequest)
}

void demoRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  request_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

demoRequest::~demoRequest() {
  // @@protoc_insertion_point(destructor:demo.demoRequest)
  SharedDtor();
}

void demoRequest::SharedDtor() {
  if (request_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_;
  }
  if (this != default_instance_) {
  }
}

void demoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* demoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return demoRequest_descriptor_;
}

const demoRequest& demoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_demo_2eproto();
  return *default_instance_;
}

demoRequest* demoRequest::default_instance_ = NULL;

demoRequest* demoRequest::New() const {
  return new demoRequest;
}

void demoRequest::Clear() {
  if (has_request()) {
    if (request_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      request_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool demoRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:demo.demoRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string request = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_request()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->request().data(), this->request().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "request");
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
  // @@protoc_insertion_point(parse_success:demo.demoRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:demo.demoRequest)
  return false;
#undef DO_
}

void demoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:demo.demoRequest)
  // required string request = 1;
  if (has_request()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request().data(), this->request().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->request(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:demo.demoRequest)
}

::google::protobuf::uint8* demoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:demo.demoRequest)
  // required string request = 1;
  if (has_request()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request().data(), this->request().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->request(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:demo.demoRequest)
  return target;
}

int demoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string request = 1;
    if (has_request()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->request());
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

void demoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const demoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const demoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void demoRequest::MergeFrom(const demoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_request()) {
      set_request(from.request());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void demoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void demoRequest::CopyFrom(const demoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool demoRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void demoRequest::Swap(demoRequest* other) {
  if (other != this) {
    std::swap(request_, other->request_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata demoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = demoRequest_descriptor_;
  metadata.reflection = demoRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int demoResponse::kSolvedFieldNumber;
const int demoResponse::kResponseFieldNumber;
#endif  // !_MSC_VER

demoResponse::demoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:demo.demoResponse)
}

void demoResponse::InitAsDefaultInstance() {
}

demoResponse::demoResponse(const demoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:demo.demoResponse)
}

void demoResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  solved_ = false;
  response_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

demoResponse::~demoResponse() {
  // @@protoc_insertion_point(destructor:demo.demoResponse)
  SharedDtor();
}

void demoResponse::SharedDtor() {
  if (response_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete response_;
  }
  if (this != default_instance_) {
  }
}

void demoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* demoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return demoResponse_descriptor_;
}

const demoResponse& demoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_demo_2eproto();
  return *default_instance_;
}

demoResponse* demoResponse::default_instance_ = NULL;

demoResponse* demoResponse::New() const {
  return new demoResponse;
}

void demoResponse::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    solved_ = false;
    if (has_response()) {
      if (response_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        response_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool demoResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:demo.demoResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool solved = 1 [default = false];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &solved_)));
          set_has_solved();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_response;
        break;
      }

      // optional string response = 2;
      case 2: {
        if (tag == 18) {
         parse_response:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_response()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->response().data(), this->response().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "response");
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
  // @@protoc_insertion_point(parse_success:demo.demoResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:demo.demoResponse)
  return false;
#undef DO_
}

void demoResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:demo.demoResponse)
  // optional bool solved = 1 [default = false];
  if (has_solved()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->solved(), output);
  }

  // optional string response = 2;
  if (has_response()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->response().data(), this->response().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "response");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->response(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:demo.demoResponse)
}

::google::protobuf::uint8* demoResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:demo.demoResponse)
  // optional bool solved = 1 [default = false];
  if (has_solved()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->solved(), target);
  }

  // optional string response = 2;
  if (has_response()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->response().data(), this->response().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "response");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->response(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:demo.demoResponse)
  return target;
}

int demoResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool solved = 1 [default = false];
    if (has_solved()) {
      total_size += 1 + 1;
    }

    // optional string response = 2;
    if (has_response()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->response());
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

void demoResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const demoResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const demoResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void demoResponse::MergeFrom(const demoResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_solved()) {
      set_solved(from.solved());
    }
    if (from.has_response()) {
      set_response(from.response());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void demoResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void demoResponse::CopyFrom(const demoResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool demoResponse::IsInitialized() const {

  return true;
}

void demoResponse::Swap(demoResponse* other) {
  if (other != this) {
    std::swap(solved_, other->solved_);
    std::swap(response_, other->response_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata demoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = demoResponse_descriptor_;
  metadata.reflection = demoResponse_reflection_;
  return metadata;
}


// ===================================================================

demoService::~demoService() {}

const ::google::protobuf::ServiceDescriptor* demoService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return demoService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* demoService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return demoService_descriptor_;
}

void demoService::Solve(::google::protobuf::RpcController* controller,
                         const ::demo::demoRequest*,
                         ::demo::demoResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Solve() not implemented.");
  done->Run();
}

void demoService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), demoService_descriptor_);
  switch(method->index()) {
    case 0:
      Solve(controller,
             ::google::protobuf::down_cast<const ::demo::demoRequest*>(request),
             ::google::protobuf::down_cast< ::demo::demoResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& demoService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::demo::demoRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& demoService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::demo::demoResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

demoService_Stub::demoService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
demoService_Stub::demoService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
demoService_Stub::~demoService_Stub() {
  if (owns_channel_) delete channel_;
}

void demoService_Stub::Solve(::google::protobuf::RpcController* controller,
                              const ::demo::demoRequest* request,
                              ::demo::demoResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace demo

// @@protoc_insertion_point(global_scope)