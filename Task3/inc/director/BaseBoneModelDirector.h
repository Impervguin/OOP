#pragma once
#include "BaseDirector.h"
#include "BaseBoneModelBuilder.h"
#include "CenterStrategy.h"
#include "BoneModelReader.h"

class BaseBoneModelDirector : public BaseDirector {
    public: 
        BaseBoneModelDirector(std::shared_ptr<BoneModelReader> reader);
        
        virtual ~BaseBoneModelDirector() = 0;
        
        virtual void Create();
        virtual std::shared_ptr<Object> Get();

    protected:
        std::shared_ptr<BaseBoneModelBuilder> _builder;
        std::shared_ptr<BaseCenterStrategy> _strategy;
        std::shared_ptr<BoneModelReader> _reader;
};