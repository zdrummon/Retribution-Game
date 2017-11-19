#pragma once

class MapTerrain {
	public:
		MapTerrain();
		
	protected:
	private:
};

class InteractiveTerrain : MapTerrain {
	public:
		InteractiveTerrain();
		
	protected:
	private:	
};

class Mob : InteractiveTerrain { 
	public:
		Mob();
		
	protected:
	private:
};

class Item : Mob { 
	public:
		Item();
		
	protected:
	private:
};

class NPC : Mob { 
	public:
		NPC();
		
	protected:
	private:
};

class PC : Mob { 
	public:
		PC();
		
	protected:
	private:
};
