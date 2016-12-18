// Copyright (c) 2016 Doyub Kim

#include <pch.h>
#include <jet/rigid_body_collider2.h>

using namespace jet;

RigidBodyCollider2::RigidBodyCollider2(const Surface2Ptr& surface) {
    setSurface(surface);
}

RigidBodyCollider2::RigidBodyCollider2(
    const Surface2Ptr& surface,
    const Vector2D& linearVelocity_,
    double angularVelocity_,
    const Vector2D& rotationOrigin_)
: linearVelocity(linearVelocity_)
, angularVelocity(angularVelocity_)
, rotationOrigin(rotationOrigin_) {
    setSurface(surface);
}

Vector2D RigidBodyCollider2::velocityAt(const Vector2D& point) const {
    Vector2D r = point - rotationOrigin;
    return linearVelocity + angularVelocity * Vector2D(-r.y, r.x);
}

RigidBodyCollider2::Builder RigidBodyCollider2::builder() {
    return Builder();
}

RigidBodyCollider2::Builder&
RigidBodyCollider2::Builder::withSurface(const Surface2Ptr& surface) {
    _surface = surface;
    return *this;
}

RigidBodyCollider2::Builder&
RigidBodyCollider2::Builder::withLinearVelocity(
    const Vector2D& linearVelocity) {
    _linearVelocity = linearVelocity;
    return *this;
}

RigidBodyCollider2::Builder&
RigidBodyCollider2::Builder::withAngularVelocity(double angularVelocity) {
    _angularVelocity = angularVelocity;
    return *this;
}

RigidBodyCollider2::Builder&
RigidBodyCollider2::Builder::withRotationOrigin(
    const Vector2D& rotationOrigin) {
    _rotationOrigin = rotationOrigin;
    return *this;
}

RigidBodyCollider2 RigidBodyCollider2::Builder::build() const {
    return RigidBodyCollider2(
        _surface,
        _linearVelocity,
        _angularVelocity,
        _rotationOrigin);
}