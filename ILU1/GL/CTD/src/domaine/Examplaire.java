package domaine;

public class Examplaire {
	private String cote;
	private boolean empruntable = true;
	private boolean online = true;
	
	public Examplaire(String cote) {
		this.cote = cote;
	}

	public String getCote() {
		return cote;
	}

	public boolean isEmpruntable() {
		return empruntable;
	}

	public boolean isOnline() {
		return online;
	}
}
