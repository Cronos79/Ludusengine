#pragma once
#include "Ludus.h"

class LDGApp : public Ludus::Application
{
public:
	LDGApp(const Ludus::ApplicationSpecification& spec);	

	~LDGApp();

	void Begin() override;


	void Tick(float dt) override;

};